#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readString() {
   int   l = 1; // start with enough space to hold the emtpy string.
   char* s = malloc(l * sizeof(char));
   int i = 0;
   char ch;
   while ((ch = getchar()) != '\n') {
      if (i == l-1) {
         s = realloc(s,l*2*sizeof(char));
         l *= 2;
      }
      s[i++] = ch;
   }
   s[i] = 0;
   return s;
}

int exp(int tar, int val);
unsigned long hashString(char* s) {
    /* Q2. Implement the hashString function
     * TODO compute the hash of the input string s
     * return the hash value */
    unsigned long output = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        output += (s[i] * exp(26, (strlen(s) - 1 - i)));
    }
    return output; /* fix me */
}

int exp(int tar, int val)
{
    if (val == 0)
    {
        return 1;
    }
    return tar * exp(tar, val - 1);
}

int main() {
   char buf[512];
   char* str = readString();
   printf("Hash of [%s] is %lu\n",str,hashString(str));
   free(str);
   return 0;
}
