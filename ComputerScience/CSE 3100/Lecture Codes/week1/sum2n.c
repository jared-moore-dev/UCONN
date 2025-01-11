// Compute the sum of integers from 1 to n, for a given n
#include <stdio.h>

int main(void){
  int i, n, sum;
  sum = 0;
  printf("Enter n:\n");
  scanf("%d", &n);
  i = 1;
  while (i <= n) {
    sum = sum + i;
    i++;
  }
  printf("Sum from 1 to %d = %d\n", n, sum);
  return 0;
}

