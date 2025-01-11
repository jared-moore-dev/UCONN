#include <stdlib.h>

struct Person {
    int age;
    char gender;
};

int main(){
    struct Person p;
    p.age = 42;
    p.gender = 'M';

    struct Person d = {32,'F'};
    return 0;
}