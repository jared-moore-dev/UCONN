#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <string.h>
#include <errno.h>
#include "matrix.h"

/* Convenience function to load a matrix from a file */
Matrix* loadMatrix(char* fName)
{
   FILE* fd = fopen(fName,"r");
   if (fd==NULL) return NULL;
   Matrix* m = readMatrix(fd);
   fclose(fd);
   return m;
}

int main(int argc,char* argv[])
{
   if (argc < 4) {
      printf("usage: mult <file1> <file2> <#workers>\n");
      exit(1);
   }
   Matrix* a = loadMatrix(argv[1]);
   Matrix* b = loadMatrix(argv[2]);
   int nbW = atoi(argv[3]);
   if (a==NULL || b==NULL) {
      printf("Wrong filenames. Couldn't load matrices [%s,%s]\n",argv[1],argv[2]);
      exit(2);
   }

   // TODO
    //  make a semaphore
   char* zone = "/memzone1";
   int sfd = shm_open(zone, O_RDWR | O_CREAT, S_IRWXU);

   // Make a Matrix
   size_t matrixSize = sizeMatrix(a->r, b->c);
   size_t nbPages = 1 + matrixSize/4096;
   size_t mapSize = matrixSize * 4096;

   int status = ftruncate(sfd, mapSize);
   void* mem = mmap(NULL, mapSize,
                     PROT_READ | PROT_WRITE,
                     MAP_SHARED| MAP_FILE,
                     sfd, 0);
   sem_t* sem = sem_open("/sem1",O_CREAT,0666,0);

   Matrix* e = makeMatrixMap(mem, a->r, b->c);
   e = parMultMatrix(nbW,  sem, a, b, e);
   printMatrix(e);
   //unmap memory
   munmap(mem, mapSize);
   // Close and unlink semaphore
   sem_close(sem);
   sem_unlink("/sem1");
   shm_unlink(zone);
   close(sfd);
   // Carry out the computation and print the resulting matrix. 

   return 0;
}
