#include <stdio.h>

int main(int argc, char* argv[]){
  printf("n = ");
  int n;
  scanf("%d", &n); /*my take input*/
  unsigned int denom = 1;
  double e = 0;
  for(int i = 1; i <= n+1; i++){
    	e = e + (1.0/denom); /* calculate summation*/
    	denom = denom * i; /* accrue denom (k)*/
  	}
  printf("e =  %lf\n", e);
}
