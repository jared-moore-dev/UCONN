#include "hamming.h"
#include <stdio.h>

/* Q3: Write a test program that reads two strings from the standard input (of arbitrary lengths)
       and compute their hamming distance. The user input is not guaranteed to give strings
       of the same length!
       
       Your code cannot have memory leaks or memory corruptions. We will check with valgrind.

   Example:
   input:
   qwerty uiop asdf
   qwerty ui0p a3df
   output:
   hd:2

   Don't forget to handle the case of inputs of different lengths.
*/

int main()
{
   // TODO: Implement the top-level test
   char* ui1 = readString();
   char* ui2 = readString();
   char* s1 ="thing";
   char* s2 ="fling";
   char* s3 ="bingus";
   char* s4 ="bingus";
   char* s5 ="";
   int uit1 = computeHD(ui1, ui2);
   printf("hd: %d", uit1);
   int a1 = computeHD(s1, s2);
   int a2 = computeHD(s3, s4);
   int a3 = computeHD(s4, s5);
   printf("comparing %s and %s, difference of %d", s1, s2, a1);
   printf("comparing %s and %s, difference of %d", s3, s4, a2);
   printf("comparing %s and %s, difference of %d", s4, s5, a3);
   return 0;
}
