#include <stdio.h>
#include <math.h>
int main(int argc, char* argv[]){
  double x, min = INFINITY, max = -INFINITY;
  int i = 0;
  while(scanf("%lf", &x) == 1){
    if(x > max){max = x;}
    if(x < min){min = x;}
    printf("Min=%lf Max=%lf\n", min, max);
  }

}
