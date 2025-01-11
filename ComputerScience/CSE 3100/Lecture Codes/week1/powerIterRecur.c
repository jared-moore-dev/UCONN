#include <stdio.h>

#define BASE 42
#define N 21

int poweriter;
int powerrecur;

int main(int argc, char* argv[]){
  int iter = poweriter(BASE, N);
  int recur = powerrecur(BASE,N);
  printf("iterative solution: %d\n", iter);
  printf("recursive soltuion: %d\n", recur);
  return 0;
}

int poweriter(int base, int n){
  int rv = 1;
  while (n) {
    rv *= base;
    n-= 1;
  }
  return rv;
}
int powerrecur(int base, int n){
  if (n == 0) return 1;
  else return base * powerrecur(base, n-1);
}
