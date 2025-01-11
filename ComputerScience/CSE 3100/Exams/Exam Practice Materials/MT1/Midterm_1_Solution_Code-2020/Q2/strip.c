#include "strip.h"

#include <stdio.h>
#include <stdlib.h>

int isspace(int c)
{
   return c==' ' || c=='\t' || c == '\n' || c == '\r';
}

int length(char* s)
{
   int l = 0;
   while (*s++)
      l++;
   return l;
}
char* strip(char* s)
{
   /*
    * In place trimming of s. Go to the end and zap all spaces.
    * Functions needed: strlen, isspace
    * header: string.h
    */
   size_t len = length(s);
   char* end = s + len - 1;
   while (end >= s && isspace(*end))
      --end;
   end[1] = 0;
   return s;
}

