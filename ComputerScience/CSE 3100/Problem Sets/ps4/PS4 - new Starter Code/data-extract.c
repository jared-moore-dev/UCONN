#include <stdlib.h>
#include <stdio.h>

void my_error(char *s)
{
    // print our own error message to standard error output
    fprintf(stderr, "Error:%s\n", s);
    // Use perror() to print the descriptive message about the error
    perror("errno");
    exit(EXIT_FAILURE);
}

/* This function copy integers from file infp to file outfp.
 * The integers copied are specified by start and end.  
 *
 * For example, 
 * start is 0, end is 0. 
 *      The first int in infp is copied to outfp. 
 * start is 10, end is 20. 
 *      11 integers are copied from infp to outfp, starting from integer 10.
 *
 * Functions that may be used in this function include
 * fseek(), fread(), fwrite(). 
 *
 * Check the return values of function calls.
 *
 * Return values:
 * 0:   success
 * -1:  function calls failed
 * */
int copy_integers(FILE *outfp, FILE *infp, int start, int end)
{
    // TODO
    int diff = (end-start)+1;
    int buffer[diff];
    fseek(infp,start*sizeof(int), SEEK_SET);
    fread(buffer,sizeof(int), diff, infp);
    fwrite(buffer,sizeof(int),diff,outfp);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input-filename> <output-filename> range [range ..]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE    *infp, *outfp;

    // TODO
    // open inputfile for read
    // If it fails, call my_error("Cannot open input file.");
    infp = fopen(argv[1], "rb");
    if(!infp){
        my_error("Cannot open input file.");
    }
    // open output for write
    // If it fails, call my_error("Cannot open output file.");
    outfp = fopen(argv[2], "wb");
    if(!outfp){
        my_error("Cannot open output file.");
    }

    for (int i = 3; i < argc; i ++) {
        int start, end;

        // example of using sscanf()
        if (sscanf(argv[i], "%d-%d", &start, &end) != 2) {
            if (sscanf(argv[i], "%d", &start) != 1) 
                my_error("Invalid range");
            end = start;
        }

        if (start < 0 || end < 0 || end < start) 
            my_error("start and end must be >= 0 and start must be <= end");
        if (copy_integers(outfp, infp, start, end)) 
            my_error("copy_integers() reteurned a non-zero value.");
    } 

    // TODO

    // close files
    if(fclose(infp)){
        my_error("Cannot close input file.");
    }
    if(fclose(outfp)){
        my_error("Cannot close output file.");
    }

    // On error, 
    // call my_error("Cannot close input file.") or
    //      my_error("Cannot close output file.")

    return 0;
}
