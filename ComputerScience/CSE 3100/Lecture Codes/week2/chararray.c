#include <stdio.h>
int main(){
    char s[6];
    s[0] = 'H';
    s[1] = 'e';
    s[2] = 'l';
    s[3] = 'l';
    s[4] = 'o';
    s[5] = '\0';
    printf("Array is: %s\n", s);
    char b[6] = {'b','o','o','t','y', '\0'};
    printf("New Array is: %s\n", b);
    char l[6] = "Ligma";
    printf("Newest Array is: %s\n",l);
    // all these arrays are formed on the stack
}