#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int val;
  struct Node* next;
  struct Node* last;
}Node;

typedef struct DLL
{
  int size;
  Node* head;
  Node* tail;
}DLL;

DLL* initDLL()
{
  DLL* d = (DLL*) malloc(sizeof(DLL));
  //d->head = NULL;
  //d->tail = NULL;
}

void pushToFront(DLL* dll, int val)
{
  Node* n = (Node*) malloc(sizeof(Node));
  n->last = NULL;
  n->val = val;
  if (dll->size == 0)
    {
      dll->head = n;
      dll->tail = n;
      dll->size++;
      return;
    }
  dll->head->last = n;
  n->next = dll->head;
  dll->head = n;
  dll->size++;
}

void pushToBack (DLL* dll, int val)
{
  Node* n = (Node*) malloc(sizeof(Node));
  n->next = NULL;
  n->val = val;
  if (dll->size == 0)
    {
      dll->head = n;
      dll->tail = n;
      dll->size++;
      return;
    }
  dll->tail->next = n;
  n->last = dll->tail;
  dll->tail = n;
  dll->size++;
}

int popFromFront(DLL* dll)
{
  int val;
  if (dll->size == 1)
    {
      val = dll->head->val;
      free(dll->head);
      dll->head = NULL;
      dll->tail = NULL;
      dll->size--;
      return val;
    }
  val = dll->head->val;
  dll->head = dll->head->next;
  free(dll->head->last);
  dll->head->last = NULL;
  dll->size--;
  return val;
}

int popFromBack(DLL* dll)
{
  int val;
  if (dll->size == 1)
    {
      val = dll->head->val;
      free(dll->head);
      dll->head = NULL;
      dll->tail = NULL;
      dll->size--;
      return val;
    }
  val = dll->tail->val;
  dll->tail = dll->tail->last;
  free(dll->tail->next);
  dll->tail->next = NULL;
  dll->size--;
  return val;
}

int main()
{
  DLL* dll = initDLL();
  pushToFront(dll, 3);
  pushToFront(dll, 2);
  pushToFront(dll, 1);
  pushToBack(dll, 4);
  pushToBack(dll, 5);
  pushToBack(dll, 6);
  printf("%d\n", popFromFront(dll));
  printf("%d\n", popFromFront(dll));
  printf("%d\n", popFromFront(dll));
  printf("%d\n", popFromBack(dll));
  printf("%d\n", popFromBack(dll));
  printf("%d\n", popFromBack(dll));
  return 0;
}
