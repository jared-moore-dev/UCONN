#include <stdio.h>

/* Q1. Implement the functions getMSDigit() and main() */

int getMSDigit(int x)
{
   // TODO: extract the leading digit of integer x and return it
   while(x > 10){
       x = x/10;
   }
   return x; /* fix me */
}

int main()
{
   /* TODO: read input from the stdin
    * for each integer, obtain the leading digit
    * calculate the frequencies of the leading digits
    * print the frequencies on stdout */
    int freq[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // get first char
    char c = getchar();
    // store val if its not whitespace
    int tempVal = (c == ' ');
    //while loop
    while(c != EOF)
    {
        // it exists case
        if (tempVal == 0 && c != ' ')
        {
            freq[c - '0']++;
            tempVal = 1;
        }
        // whitespace case
        if (c == ' ')
        {
            tempVal = 0;
        }
        // get next character
        c = getchar();
    }
    // print out
    printf("0:%d 1:%d 2:%d 3:%d 4:%d 5:%d 6:%d 7:%d 8:%d 9:%d", freq[0], freq[1], freq[2], freq[2], freq[3], freq[4], freq[5], freq[6], freq[7], freq[8], freq[9]);
    return 0;
  }
