#include <stdio.h>
#include <stdlib.h>

int main(){
    int* t = (int*)malloc(sizeof(int)*10);
    int* p = t + 9;
    int dist = p - t;
    printf("Distance is %d\n", dist);
    return 0;
}
