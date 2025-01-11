typedef union SomeValue {
  long aLong;
  float aFloat;
  char* name;
} SomeValue;

int main(){
  SomeValue x;
  x.aLong = 42;
  return 0;
}
