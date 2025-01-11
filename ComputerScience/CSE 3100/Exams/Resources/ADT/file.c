FILE* file = fopen(argv[1], "r");
fclose(file);
// "r":  Opens a file for reading. The file must exist.

// "w":  Creates an empty file for writing. If a file with the same name already exists, its content is erased and the file is considered as a new empty file.

// "a":  Appends to a file. Writing operations, append data at the end of the file. The file is created if it does not exist.

// "r+":  Opens a file to update both reading and writing. The file must exist.

// "w+":  Creates an empty file for both reading and writing.

// "a+":  Opens a file for reading and appending.

#include <stdio.h>

int main () {
    FILE *fp;
    int c;
    int n = 0;

    fp = fopen("file.txt","r");
    if(fp == NULL) {
        perror("Error in opening file");
        return(-1);
    } do {
        c = fgetc(fp);
        if( feof(fp) ) {
            break ;
        }
        printf("%c", c);
    } while(1);

    fclose(fp);
    return(0);
}
// next
