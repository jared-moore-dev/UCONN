#include <stdio.h>
#include <stdlib.h>
#define MAX 2147483647
#define N 10000


#define RANDPOINT (1.0*(rand() % MAX)/MAX)
/*
  TODO: Comment out the following two defines, and replace them with functions.
 */
/*
#define DISTSQUARED(x, y) (x*x + y*y)
#define SAMPLE (DISTSQUARED(RANDPOINT, RANDPOINT) <= 1)
*/
double DISTSQUARED(double x, double y){
	return (x*x + y*y);
}
int SAMPLE(){
	return (DISTSQUARED(RANDPOINT, RANDPOINT) <=1);
}

int main(int argc, char* argv[]){
  srand(10);
  unsigned int j = 0;
  for(unsigned int i = 0; i < N; i++){
    if(SAMPLE()){
      j++;
    }
  }
  double pi = 4.0*j/N;
  printf("pi: %f\n", pi);  
}
