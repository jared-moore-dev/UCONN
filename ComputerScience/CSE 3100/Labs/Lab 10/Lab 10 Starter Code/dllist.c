#include "dllist.h"
#include <stdio.h>
#include <assert.h>

void initList(DLList* list)
{
   list->head = list->tail = NULL;
   pthread_mutex_init(&list->mtx,NULL);
}
void clearList(DLList* list)
{
   DLNode* cur = list->head;
   while (cur) {
      DLNode* next = cur->next;
      pthread_mutex_destroy(&cur->mtx);
      free(cur);
      cur = next;
   }
   list->head = list->tail = NULL;
}
void destroyList(DLList* list)
{
   clearList(list);
   pthread_mutex_destroy(&list->mtx);
}

void insertSortedList(DLList* list,int v)
{
  /*
    TODO: Iterate through the list, find the correct place to insert the integer v. Each node has a mutex; use those mutexes to coordinate the threads. 
   */
  // make a new node
    DLNode* nn = (DLNode*)malloc(sizeof(DLNode));
    nn->value =v;
    pthread_mutex_init(&nn->mtx,NULL);
    pthread_mutex_lock(&list->mtx);
    // Edge Case: The list is empty
    if(list->head == NULL){
        nn->next=NULL;
        nn->prv =NULL;
        list->head = nn;
        list->tail = nn;
        pthread_mutex_unlock(&list->mtx);
        return;
    }
    // Ladder Lock through the list to the insert point
    DLNode* cur = list->head;
    pthread_mutex_t* pLock = &list->mtx;
    while (cur){
        pthread_mutex_lock(&cur->mtx);
        if(cur->value <= v){
            pthread_mutex_unlock(pLock);
            pLock = &cur->mtx;
            cur = cur->next;

        }else{
            break;
        }
    }
    if (cur) {
        // We are before cur
        DLNode* prev = cur->prv; //prev = locked node

        DLNode* nxt  = cur; //cur = our node
        nn->prv = prev; // set the prev of nn to be prev
        nn->next = cur; // set the next of nn be cur (nn now in between)
        if (prev)
        {
            prev->next = nn;    //still have prev locked
        }
        else
        {
            list->head = nn;    //edgecase no lock
        }
        nxt->prv = nn;
        pthread_mutex_unlock(&cur->mtx);
    } else {
        // nn is being inserted at the end of the list
        nn->next = NULL;
        pthread_mutex_lock(&list->mtx);
        nn->prv = list->tail;
        if (list->tail)
            list->tail->next = nn;
        else list->head = nn;
        list->tail = nn;
        pthread_mutex_unlock(&list->mtx);
    }
    pthread_mutex_unlock(pLock);
}
/*
 * void insertSortedList(DLList* list,int v)
{
   DLNode* cur = list->head;
   while (cur && cur->value <= v)
      cur = cur->next;
   if (cur) {
      // We found the spot: before `cur`
      DLNode* prev = cur->prv;
      DLNode* nxt  = cur;
      DLNode* nn = malloc(sizeof(DLNode));
      nn->value = v;
      nn->prv = prev;
      nn->next = cur;
      if (prev) prev->next = nn;
      else list->head = nn;
      nxt->prv = nn;
   } else {
      DLNode* nn = malloc(sizeof(DLNode));
      nn->value = v;
      nn->next = NULL;
      nn->prv = list->tail;
      if (list->tail)
         list->tail->next = nn;
      else list->head = nn;
      list->tail = nn;
   }
}
 */

void printListForward(DLList* list)
{
   pthread_mutex_lock(&list->mtx);
   DLNode* cur = list->head;
   pthread_mutex_t* last = &list->mtx;
   while (cur) {
      pthread_mutex_lock(&cur->mtx);
      printf("%d ",cur->value);
      pthread_mutex_unlock(last);
      last = &cur->mtx;
      cur = cur->next;
   }
   printf("\n");
   pthread_mutex_unlock(last);
}