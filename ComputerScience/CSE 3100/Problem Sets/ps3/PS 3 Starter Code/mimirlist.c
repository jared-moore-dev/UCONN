#include "list.h"
#include <stdio.h>
#include <assert.h>

int main(){
    IntList* list = malloc(sizeof(IntList));
    initList(list);
    pushBackList(list, 1);
    pushFrontList(list, 8);
    pushFrontList(list, 3);
    pushBackList(list, 2);
    pushBackList(list, 12);
    pushBackList(list, 5);
    sortList(list);
    printList(list);
    popFrontList(list);
    popBackList(list);
    popFrontList(list);
    popBackList(list);
    popBackList(list);
    printList(list);
    popFrontList(list);
}
