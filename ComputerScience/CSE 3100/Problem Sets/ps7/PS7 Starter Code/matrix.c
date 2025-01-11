#include "matrix.h"
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <semaphore.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

size_t sizeMatrix(int r,int c)
{
   /*
    * returns the nummber of bytes needed to hold a matrix of r x c values (type int)
    */
   return r * c * sizeof(int)+sizeof(Matrix);
}

Matrix* makeMatrix(int r,int c)
{
   /*
    * allocates space to hold a matrix of r x c values (type int)
    */
   // Allocate memory, then point c and r to c and r
   Matrix* newMatrix = malloc(sizeMatrix(r,c));
   newMatrix->c = c;
   newMatrix->r = r;
   return newMatrix;
}

Matrix* makeMatrixMap(void* zone,int r,int c)
{
   /*
    * Allocates space for a matrix of r x c from a _given_ memory block at address zone. 
    */
    Matrix* newMatrix = zone;
    newMatrix->c = c;
    newMatrix->r = r;
    return newMatrix;
}

/**
 * Reads a single integer from the FILE fd
 * output: a single integer.
 * Note: the function uses getc_unlocked to _not_ pay the overhead of locking and
 * unlocking the file for each integer to be read (imagine reading a matrix of 1000x1000,
 * that's 1,000,000 calls to getc and therefore 1,000,000 calls to locking the file. 
 */
int readValue(FILE* fd)
{
   int v = 0;
   char ch;
   int neg=1;
   while (((ch = getc_unlocked(fd)) != EOF) && isspace(ch)); // skip WS.      
   while (!isspace(ch)) {
      if (ch=='-')
         neg=-1;
      else
         v = v * 10 + ch - '0';
      ch = getc_unlocked(fd);
   }
   return neg * v;
}

Matrix* readMatrix(FILE* fd)
{
   /*
    * Read a matrix from a file (fd). The matrix is held in a text format that first conveys
    * the number of rows and columns, then, each row is on a line of text and all the 
    * values are separated by white spaces. 
    * Namely:
    * r c
    * v0,0 v0,1 .... v0,c-1
    * v1,0 v1,1 .... v1,c-1
    * ....
    * vr-1,0 ....    v_r-1,c-1
    */
   int r,c,v;
   int nv = fscanf(fd,"%d %d",&r,&c);
   Matrix* m = makeMatrix(r,c);
   flockfile(fd);
   for(int i=0;i < r;i++)
      for(int j=0;j < c;j++) {
         v = readValue(fd);
         M(m,i,j) = v;
      }
   funlockfile(fd);
   return m;
}


void freeMatrix(Matrix* m)
{
   /*
    * deallocates the space used by matrix m
    */
   free(m);
}
void printMatrix(Matrix* m)
{
   /*
    * Print the matrix on the sandard output. One row per line, values for the row
    * separated by white spaces. 
    */
   int k = 1;
   for(int i = 0; i<(m->c * m->r); i++){
       int col = i % m->c;
       int row = i / m->c;
       int cords = M(m,row,col);

       if(k == m->c){
           printf("%d", cords);
           printf("\n");
           k = 0;
       } else {
           printf("%d ", cords);
       }
       k++;
   }
}

Matrix* multMatrix(Matrix* a,Matrix* b,Matrix* into)
{  // mxn * nxp yields an mxp matrix
   /*
    * Compute the produce of A * B and store the result in `into`.
    * The computation is sequential and is only meant to be used as a
    * check for your parallel code. 
    *
    * Return value: the matrix `into` were the result is held.
    */
   for(int i = 0; i < a->r; i++){
       for(int j = 0; j < b->c; j++){
           int prod = 0;
           for(int k = 0; k < b->r; k++){
               prod += M(a, i, k) * M(b, k, j);
           }
           M(into, i,j) = prod;
       }
   }
}

Matrix* parMultMatrix(int nbW,sem_t* sem,Matrix* a,Matrix* b,Matrix* into)
{
   /*
    * Compute the produce of A * B and store the result in `into`
    * The compuration is done in parallel with nbW worker **processes** (NOT threads). 
    * It should have the same output as the sequential version, but faster. ;-)
    * How you use the semaphore is up to you (as long as you use it!)
    * You CANNOT use the wait system call. 
    *
    * Return value: the matrix `into` were the result is held.
    */
   into->c = b->c;
   into->r = a->r;
   int diff = 0;
   int nRow = into->r/nbW;
   int row = into->r % nbW;

   int* segment = (int*)malloc(sizeof(int) * nbW);
   memset(segment, 0, sizeof(segment));
   for(int k = 0; k < nbW; k++){
       segment[k] = nRow;
       if(row > 0){
           segment[k]++;
           row--;
       }
   }
   for(int w = 0; w < nbW; w++){
       pid_t worker = fork();

       if(worker==0){
           for(int i = diff; i < diff + segment[w]; i++){
               for(int j = 0; j < into->c; j++){
                   int total=0;
                   for(int k=0; k<b->r;k++){
                       total += M(a,i,k) * M(b, k, j);
                   }
                   M(into, i, j) = total;
               }
           }
           sem_post(sem);
           exit(0);
       } else {
           diff += segment[w];
       }
   }
   for(int z = 0; z < nbW; z++){
       sem_wait(sem);
   }
   return into;
}
