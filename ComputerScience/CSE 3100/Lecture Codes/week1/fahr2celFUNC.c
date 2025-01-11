#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 10
int fahrToCelcius(int degF);

int main(int argc, char* argv[]){
  for(int fahr=LOWER; fahr <= UPPER; fahr+=STEP){
    int celcius = fahrToCelcius(fahr);
    printf("From %d F to %d C degrees\n", fahr, celcius);
  }
  return 0;
}
int fahrToCelcius(int degF){
  return 5*(degF-32)/9;
}
