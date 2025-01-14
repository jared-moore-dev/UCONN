#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define     LINE_SIZE   1024

void my_error(char *s)
{
    fprintf(stderr, "Error: %s\n", s);
    perror("errno");
    exit(-1);
} 

// This funciton prints lines (in a file) that contain string s.
// assume all lines has at most (LINE_SIZE - 2) ASCII characters.
//
// Functions that may be called in this function:
// fopen(), fclose(), fgets(), fputs(), strstr() 
//
// Paramters:
//  s: the string
//  filename: the file to be searched
// Return values:
//  0:  success.
//  EOF: cannot open or close file.
int print_matched_lines(const char *s, const char *filename)
{
    // init variables
    FILE *fp = NULL;
    char lineBuffer[LINE_SIZE];
    int count = 0;
    // open the file
    fp = fopen(filename, "r");
    if(!fp){
      fprintf(stderr, "Error - unable to open %s\n", filename);
      return EOF;
    }
    // loop through file
    while(fgets(lineBuffer, LINE_SIZE, fp)){
      // print every line where strstr(linebuffer, s) returns a val
      if(strstr(lineBuffer, s)){
        printf("%s", lineBuffer);
        ++count;
      }
    }
    fclose(fp);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <string> <filename>\n", argv[0]);
        return -1;
    }

    // print_matched_lines() to print any lines in file argv[2] that contains arg[1]

    if (print_matched_lines(argv[1], argv[2])) {
        my_error("print_matched_lines() retunred a non_zero value.");
    }
    return 0;
}
