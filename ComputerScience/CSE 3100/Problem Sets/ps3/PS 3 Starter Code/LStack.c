#include "LStack.h"


void initStack(Stack * s)
{
  initList(&(s->list));
}
void pushStack(Stack* stack, int number)
{
  pushBackList(&(stack->list), number);
}
int popStack(Stack* stack)
{
  return popBackList(&(stack->list));
}
void freeStack(Stack* stack)
{
    freeList(&(stack->list));
}

void printStack(Stack* stack)
{
    printList(&(stack->list));
}

int isEmpty(Stack* stack)
{
  return (lengthList(&(stack->list)) == 0);
}
