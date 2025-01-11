#include "upper.h"
#include <stdio.h>
#include <stdlib.h>

static int isspace(int c)
{
   return c==' ' || c=='\t' || c == '\n' || c == '\r';
}

static int length(char* s)
{
   int l = 0;
   while (*s++)
      l++;
   return l;
}

static char* strip(char* s)
{
   size_t len = length(s);
   char* end = s + len - 1;
   while (end >= s && isspace(*end))
      --end;
   end[1] = 0;
   return s;
}

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
   char* up = strupper(strip(line));
   printf("[%s]\n",up);
   free(up);
   free(line);
   return 0;
}
