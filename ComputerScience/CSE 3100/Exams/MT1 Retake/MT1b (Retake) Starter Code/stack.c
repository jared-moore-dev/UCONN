#include "stack.h"
#include <stdlib.h>

IStack* makeStack()
{
   IStack* s = (IStack*)malloc(sizeof(IStack));
   s->mx = 2;
   s->sz = 0;
   s->t = (int*)malloc(sizeof(int)*s->mx);
   return s;
}

void freeStack(IStack* s)
{
   free(s->t);
   free(s);
}
void pushStack(IStack* s,int v)
{
   if (s->sz >= s->mx) {
      s->t = (int*)realloc(s->t,sizeof(int)* s->mx * 2);
      s->mx *= 2;
   }
   s->t[s->sz++] = v;
}
int popStack(IStack* s)
{
   return s->t[--s->sz];
}
int isEmptyStack(IStack* s)
{
   return s->sz == 0;
}
