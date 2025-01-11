#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 10
int main(int argc, char* argv[]){
  int celcius, fahr;
  for(fahr=LOWER; fahr <= UPPER; fahr += STEP){
    celcius = 5* (fahr - 32) / 9;
    printf("From %d F to %d C degrees\n", fahr,celcius);
  }
  return 0;
}
