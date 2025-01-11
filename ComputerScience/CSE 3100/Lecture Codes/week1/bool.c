#include <stdio.h>

#define BOOL char
#define TRUE 1
#define FALSE 0

int main(int argc,char* argv[]){
  BOOL x = TRUE;
  BOOL y = FALSE;
  BOOL w,z;

  z = x || y;
  w = x && y;
  printf("z is = %d\n",z);
  printf("w is = %d\n",w);
  return 0;
}
