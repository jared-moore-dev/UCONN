#include <stdio.h>

int main(int argv, char* argc[]){
  char s[7] = "123456";
  int i = 0;
  int n = 0;
  while(s[i] != 0){
    n = n*10;
    n = n+(s[i] - '0');
    i += 1;
  }
  printf("converted: %d\n", n);
  return 0;
}

