#include <stdio.h>
#include <math.h>

int main()
{
   int n,sum = 0,sumsq = 0,nb = 0;
   while (scanf("%d",&n) == 1) {
      sum += n;
      sumsq += n*n;
      ++nb;
   }
   float mu = (float)sum / nb;
   float mu2 = (float)sumsq / nb;
   float sig = sqrt(mu2 - mu*mu);
   printf("mu=%f sig=%f\n",mu,sig);
   return 0;
}
