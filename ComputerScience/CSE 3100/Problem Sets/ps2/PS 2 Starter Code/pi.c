#include <stdio.h>
#include <assert.h>
double leibnizRecurrent(int n)
{
  /* TODO: Fill in a recurrent version. That is, compute the term for n plus leibnizRecurrent(n - 1) */
  if(n==0){
    /*Basecase*/
    return 1.0;
  }else if(n%2 == 0){
    /*if n is even use positive 1.0*/
    return (1.0/(2*n + 1)) + leibnizRecurrent(n - 1);
  }else{
    /*if n is odd (else) use negative 1.0*/
    return leibnizRecurrent(n-1) - (1.0/(2*n + 1));
  }
}

double leibnizIterative(int n)
{
  /* TODO: Fill in the iterative version. That is, use a loop to compute the summation. */
  double pi = 0;
  for(int k = 0; k<= n; k++){
    if(k%2 == 0){
      pi += (1.0/(2*k+1));
    }else{
      pi -= (1.0/(2*k+1));
    }
  }
}

int main(int argc, char* argv[]){
  if(argc != 3){
    printf("Usage: ./pi <mode> <n>, where <mode> is 1 for recurrent version, and 2 is for the iterative version, and n is the upper bound of the summation.\n");
  }else{
    int mode = 0, n = 0;
    double pi = 0;
    assert(sscanf(argv[1], "%d", &mode) == 1);
    assert(sscanf(argv[2], "%d", &n) == 1);
    assert(mode == 1 || mode == 2);
    assert(n >= 0);
    if(mode == 1){
      pi = 4*leibnizRecurrent(n);
    }else{
      pi = 4*leibnizIterative(n);
    }
    printf("PI: %f\n", pi);
  }
  return 0;
}
