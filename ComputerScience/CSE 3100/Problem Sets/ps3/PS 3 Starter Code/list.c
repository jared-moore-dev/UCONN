#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


void initList(IntList* list)
{
   list->head = NULL;
   list->tail = NULL;
   list->len = 0;
}
void freeList(IntList* list)
{
  ILNode* current = list->head;
  while(current){
    ILNode* temp = current->next;
    free(current);
    current = temp;
  }
}

void pushBackList(IntList* list, int number)
{
   ILNode* node = malloc(sizeof(ILNode));
   node->number = number;
   node->next = NULL;
   // if the list is not NULL
   if(list->head){
       // multi item list
       list->tail->next = node;
       list->tail = node;
   } else {
       // new list
       list->head = node;
       list->tail = node;
   }
   list->len++;
}
int popBackList(IntList* list)
{
  assert(list->head && list->tail && list->len > 0);
  int number = list->tail->number;
  ILNode* curnode = list->head;
  ILNode* prev = NULL;
  // while the current node and the next node are not NULL
  while(curnode && curnode->next){
      prev = curnode;
      curnode = curnode->next;
  }
  // we are now at the end of the list (but not at list->next, which is NULL)
  free(curnode);
  list->tail = prev;
  // if list is longer than 1
  if(list->tail){
      list->tail->next = NULL;
  } else {
      list->head = NULL;
  }
  list->len--;
  return number;
}
void pushFrontList(IntList* list, int number)
{
    ILNode* node = malloc(sizeof(ILNode));
    node->number = number;
    node->next = list->head;
    list->head = node;
    // case to catch first item added to a list
    if(list->tail == NULL){
        list->tail = list->head;
    }
    list->len++;
}
int popFrontList(IntList* list)
{
  assert(list->head && list->tail && list->len > 0);
  int n = list->head->number;
  ILNode* prevhead = list->head;
  list->head = list->head->next;
  if(list->head == NULL){
      list->tail = NULL;
  }
  free(prevhead);
  list->len--;
  return n;
}

void sortedInsert(IntList* sortedList, ILNode* nodeToInsert){
    if(sortedList->head == NULL){
        nodeToInsert->next = NULL;
        sortedList->head = nodeToInsert;
        sortedList->tail = nodeToInsert;
    } else {
        ILNode* curnode = sortedList->head;
        ILNode* prev = NULL;
        // while the current node exists and the number is less than NTI's number, traverse the list
        while(curnode && curnode->number < nodeToInsert->number){
            prev = curnode;
            curnode = curnode->next;
        }
        // last item, make prev point to inserted node, and set head and tail
        nodeToInsert->next = curnode;
        if(prev){
            prev->next = nodeToInsert;
        } else {
            sortedList->head = nodeToInsert;
        }
        if(curnode == NULL){
            sortedList->tail = nodeToInsert;
        }
        sortedList->len++;
    }
}

void sortList(IntList* list)
{
  IntList newList = {NULL,NULL};
  ILNode* next = NULL;
  ILNode* cur = list->head;
  while(cur){
    next = cur->next;
    sortedInsert(&newList, cur);
    cur = next;
  }
  *list = newList;
  list->len++;
}



int lengthList(IntList* list)
{
  return list->len;
}
void printList(IntList* list)
{
   printf("(");
   ILNode* node = list->head;
   while (node) {
      printf("%d ", node->number);
      node = node->next;
   }
   printf(")\n");
}
