#include "matrix.h"
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>

/* TODO: Complete functions detMatrix and detMatrixPar for Q2 */
// Store values to unpack since it takes a void*
typedef struct ADT{
    int det;
    Matrix* m;
} Structure;

Matrix* makeMatrix(int r,int c)
{
   Matrix* m = malloc(sizeof(Matrix) + r * c * sizeof(int));
   m->r = r;
   m->c = c;
   return m;
}

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

Matrix* loadMatrix(char* fName)
{
   FILE* fd = fopen(fName,"r");
   if (fd==NULL) return NULL;
   Matrix* m = readMatrix(fd);
   fclose(fd);
   return m;
}

void freeMatrix(Matrix* m)
{
   free(m);
}

void printMatrix(Matrix* m)
{
   for(int i=0;i<m->r;i++) {
      for(int j=0;j < m->c; j++)
         printf("%3d ",M(m,i,j));     
      printf("\n");
   }
}
Matrix* ColumnSkipper(Matrix* m, int column){
    Matrix* into = makeMatrix(m->r - 1, m->c - 1);
    int newrow = 0;
    int newcol = 0;
    // Iterate through all the rows and collumns, adding them to into
    // and omiting the column you want to skip
    for (int row = 1; row < m->c; row++){
        for (int col = 0; col < m->c; col++){
            // if your column is not the skipped column
            if (col != column){
                // this is your case when not in the column to omit
                M(into, newrow, newcol) = M(m, row, col);
                newcol++;
                // if you're at the end of a row, increase row and set col to 0
                if (newcol == m->c - 1){
                    newrow++;
                    newcol = 0;
                }
            }
        }
    }
    return into;
}

int detMatrix(Matrix* m)
{
   /* TODO 
    * This function calculates the determinant of matrix m sequentially.
    * Hint: you may create an auxiliary function for ease of implementation.
    * Note that while the indexing of the matrix starts with 0, the inductive definition in the pdf handout starts with a 1.
    * The function returns the determinant of matrix m.
    */
   // Edge Cases
   if (m->r != m->c){
       // This matrix is not square...
       exit(-1);
   } else if (m->r == 0){
       // this matrix is 0x0
       // 0x0 matrix is 1
       return 1;
   } else if (m->r == 1){
       // this matrix is 1x1
       return M(m, 0, 0);
   }

   int det = 0;
   int sign = 1;

   for (int col = 0; col < m->c; col++){
       Matrix* cofactor = ColumnSkipper(m, col);
       det += sign * M(m, 0, col) * detMatrix(cofactor);
       sign *= -1;
       freeMatrix(cofactor);
   }
   return det; /* TODO: fix me */
}
/*
int DetPartCalc(Matrix* m, int column){
    Matrix* into = makeMatrix(m->r - 1, m->c - 1);
    int newrow = 0;
    int newcol = 0;
    // Iterate through all the rows and columns, adding them to into
    // and omiting the column you want to skip
    for (int row = 1; row < m->c; row++){
        for (int col = 0; col < m->c; col++){
            // if your column is not the skipped column
            if (col != column){
                // this is your case when not in the column to omit
                M(into, newrow, newcol) = M(m, row, col);
                newcol++;
                // if you're at the end of a row, increase row and set col to 0
                if (newcol == m->c - 1){
                    newrow++;
                    newcol = 0;
                }
            }
        }
    }
    int sign = 1;
    // calculate the return values
    if (column % 2){
        // sign will be negative
        sign = -1;
    }
    int detpart = sign * M(m, 0, col) * detMatrix(into);
    return detpart;
}
 */

int detmatrixparhelper(Structure* s){

    int det = 0;

    int sign = 1;

    for (int col = 0; col < s->m->c; col++){
        Matrix* cofactor = ColumnSkipper(s->m, col);
        det += sign * M(s->m, 0, col) * detMatrix(cofactor);
        sign *= -1;
        freeMatrix(cofactor);
    }
    s->det = det;
    return 0;
}


int detMatrixPar(Matrix* m,int nbW)
{
   // Edge cases
    if (m->r != m->c){
        // This matrix is not square...
        exit(-1);
    } else if (m->r == 0){
        // this matrix is 0x0
        // 0x0 matrix is 1
        return 1;
    } else if (m->r == 1){
        // this matrix is 1x1
        return M(m, 0, 0);
    }
    Structure* s = (Structure*)malloc(sizeof(Structure));
    s->det = 0;
    s->m = m;
    // Create your threads
    pthread_t t[nbW];
    for (int i = 0; i < nbW; i++){
        pthread_create(&t[i], NULL, (void*)detmatrixparhelper, s);
    }
    for (int i = 0; i < nbW; i++){
        pthread_join(t[i], NULL);
    }
    int result = s->det;
    // Give those threads the job to do
    free(s);
    // have them run detpart

    // join them
    
    // they already recoursively calculate their dets, so theoretically sum it all the ints detpart returns and bam thats your value

    return result; /* TODO: fix me */
}
