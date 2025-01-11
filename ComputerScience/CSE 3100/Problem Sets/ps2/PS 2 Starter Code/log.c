#include <stdio.h>


double approxLog(double a, int n)
{
  /*TODO: Use trapezoid integration to approximate the logarithm*/
  double delx = (a - 1)/n;
  double area = (1.0/a + 1.0)/2.0;
  for(int k = 1; k<n; k++){
    area += 1.0/(1 + delx*k);
  }
  return delx*area;
}

int main(int argc, char* argv[])
{
  
  double a;
  int n;
  printf("Enter a: ");
  scanf("%lf", &a);
  printf("Enter n: ");
  scanf("%d", &n);
  double logarithm = approxLog(a, n);
  printf("Natural logarithm: %lf\n", logarithm);
  return 0;
}
