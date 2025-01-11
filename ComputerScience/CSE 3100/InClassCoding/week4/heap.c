#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
  int msz;
  int* t;
  int sz;
} Heap;

Heap* makeHeap(int msz);
void freeHeap(Heap* h);
void insertHeap(Heap* h,int v);
void printHeap(Heap* h);
int emptyHeap(Heap* h);
int extractMin(Heap* h);


Heap* makeHeap(int msz)
{
  int* storage =(int*)malloc(sizeof(int)*msz);
  Heap* h = (Heap*)malloc(sizeof(Heap));
  h->t = storage;
  h->msz = msz;
  h->sz = 0;
  return h;
}

void freeHeap(Heap* h)
{
  free(h->t);
  free(h);
}

void insertHeap(Heap* h,int v)
{
  if (h->sz == h->msz - 1) {
    h->t = (int*) realloc(h->t,h->msz * 2);
    h->msz *= 2;
  }
  int end = h->sz + 1;
  h->t[end] = v;
  h->sz++;
  while (end > 1) {
    int p = end / 2;
    if (h->t[p] < h->t[end])
      return ;
    else {
      h->t[end] = h->t[p];
      h->t[p] = v;
      end = p;
    }
  }
}
void printHeap(Heap* h){
  printHeapAux(h,1);
}
void printHeapAux(Heap* h, int from){
  if(from > h->sz){
    printf(".");
  } else {
    printf("( %d",h->t[from]);
    printHeapAux(h,from * 2);
    printf(" ");
    printHeapAux(h, from * 2 + 1);
    printf(")");
  }
}
int emptyHeap(Heap* h){
  return h->sz == 0;
}
void bubbleDown(Heap* h, int f){
  int newRoot = h->t[f] < h->t[2*f] ? f : 2 * f;
  newRoot = h->t[newRoot] < h->t[2*f+1] ? nr : 2*f + 1;
  int looser h->t[f];
  h->t[f] = h->t[newRoot];
  h->t[newRoot] = looser;
  bubbleDown(h, newRoot);
}

int extractMin(Heap* h){
  int rv = h->t[1];
  int newRoot = h->t[h->sz];
  h->[1] = newRoot;
  h->sz -= 1;
  bubbleDown(h,1);
  return rv;
}
int main()
{
  Heap* h = makeHeap(128);
  for(int i = 0;i < 10;i++)
    insertHeap(h,10 - i);
  printHeap(h);
  while(!emptyHeap(h)) {
    int v = extractMin(h);
    printf("Got: %d\n",v);
  }
  freeHeap(h);
  return 0;
}
