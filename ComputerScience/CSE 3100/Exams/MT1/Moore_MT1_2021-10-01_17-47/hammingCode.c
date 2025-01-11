#include "hamming.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Q1: read a string of arbitrary length from the standard input. The string is linefeed (\n)
       terminated. Think carefully of where memory is coming from as there is no upper 
       bound on the string length.
       input: none
       ouput: a pointer to a buffer container the string read. It ought to be a valid string
              (\0 terminated)
*/
char* readString()
{
   // TODO(Q1): implement this
   printf("Enter String:\n");
   int size = 100;
   char* string[size];
   fgets(string, sizeof(string), stdin);
   return string; /* FIX ME! */
}

/* Q2: compute the hamming distance between two strings. The strings are expected to be the 
       same length. The hamming distance is the number of indices where the string differ. 
       input: s1 : pointer to string 1
              s2 : pointer to string 2
       output: integer: the number of indices where the string disagree
       Note: 1. this should work for strings of any length. 
             2. You can assume that s1 and s2 have the same length.
*/

int computeHD(char* s1,char* s2)
{
   int dist = 0;
   int i = 0;
   int len1 = strlen(s1);
   int len2 = strlen(s2);
   if(len1 != len2){
     dist += 1;
   }
   while(s1[i] && s2[i]){
     if (s1[i] != s2[i]){
       dist += 1;
       i++;
     } else {
       i++;
     }
   }
   return dist; 
}
