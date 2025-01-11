#include <stdio.h>
#include <math.h>

double relError(double x, double s){
	double er;
	er = fabs(((x*x) - s)/s);
	return er;
}

int main(int argc, char* argv[]){
  double s;
  printf("Enter S to take square root of: ");
  scanf("%lf", &s);
  double guess = 1;
  while(guess*guess < s){
  	guess++;
  }

  while(relError(guess, s) > .001){
	  guess = (guess+(s/guess))*.5;
  }
  printf("Square root: %f\n", guess);
  
}
