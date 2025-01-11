#include <stdio.h>
#include <stdlib.h>

typedef union uTag {
  int iVal;
  float fVal;
  char* sVal;
} UType;

//Essentially polymorphic, can be any of its data types. Take the size of the largest data type no matter what.
//Initialize with UType


int main()
{
  return;
}
