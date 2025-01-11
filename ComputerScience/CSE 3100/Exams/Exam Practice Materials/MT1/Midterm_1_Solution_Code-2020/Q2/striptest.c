#include "strip.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
   /** 
    * Provide a template. Make sure they know how to test ?
    * Or fix the test [and include the free on the strupper output     
    */
   char* line = NULL;
   size_t len = 0;
   if (getline(&line,&len,stdin) == 0) {
      exit(1); // bad input
   }
   char* up = strip(line);
   printf("[%s]\n",up);
   free(line);
   return 0;
}
