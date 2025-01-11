#include <stdio.h>
#include "queue.h"

void initQueue(Queue* q)
{
  q->one = malloc(sizeof(Stack));
  q->two = malloc(sizeof(Stack));
  initStack(q->one);
  initStack(q->two);
}
void enQueue(Queue* q, int number)
{
  pushStack(q->one, number);
}
int deQueue(Queue* q)
{
  if(isEmpty(q->two)){
      // flip elements from stack 1 to stack 2
      while(!isEmpty(q->one)) {
          pushStack(q->two,popStack(q->one));
      }
  }
  return popStack(q->two);
}
void freeQueue(Queue* q)
{
  freeStack(q->one);
  freeStack(q->two);
}
