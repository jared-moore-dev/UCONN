#include <stdio.h>
#include <stdlib.h>

int length(char* s)
{
   char* e = s;
   while (*e) e++;
   return e - s;
}

int toupper(int c)
{
   if (c >= 'a' && c <= 'z')
      return c - 'a' + 'A';
   else return c;
}

char* strupper(char* s)
{
   /*
    * It returns a new memory block with the upper case variant of s
    * Functions needed: malloc, strlen, toupper
    * headers: string.h
    */
   char* r = malloc(length(s) + 1);
   char* d = r;
   while (*s)
      *d++ = toupper(*s++);
   return r;     
}
