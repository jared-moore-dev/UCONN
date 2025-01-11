#include <stdio.h>

int main(){
  int celcius, fahr;
  int lower, upper;
  int step;

  lower = 0;
  upper = 300;
  step = 10;
  for(fahr=lower;fahr <= upper; fahr+=step) {
    celcius = 5 * (fahr - 32) / 9;
    printf("From %d F to %d C degrees\n", fahr, celcius);
  }
  return 0;
}

