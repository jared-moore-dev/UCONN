#include <stdio.h>

int main(int argc, char* argv[]){
  printf("Please enter n, e and m: ");
  int n, e, m;
  e = 0;
  if(scanf("%d %d%d", &n, &e, &m) == 3){
    int nstart = n;
    int estart = e;
    int result = 1;
    while(e>0){
	    if (e % 2 == 1){
		    result = (result*n) %m;
	    }
	    e = e/2;
	    n = (n*n) % m;
    }
    printf("%d ** %d mod %d = %d\n", nstart, estart, m, result);
  }else{
    printf("You did not enter three integers. Exiting\n"); 
  }
}
