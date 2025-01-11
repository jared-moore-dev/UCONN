#include <stdio.h>

int func(int n, int k){
    // declare a dynamically sized array
    int x[n];
    for(int i = 0; i<n; i++){
        x[i] = 0;
    }
    x[0] = 0;
    x[1] = 1;
    for(int i = 2; i<n; i++){
        x[i] = x[i-1] + x[i-2];
        if (0 <= k && k < n){
            return x[k];
        } else {
            return -1;
        }
    }
}
int main(){
    int z = func(20, 15);
    printf("%d", z);
}