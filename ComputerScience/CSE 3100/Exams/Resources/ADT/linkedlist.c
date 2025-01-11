#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct node* next;
}Node;

typedef struct LinkedList{
    Node* head;
    Node* tail;
    int size;
}LinkedList;

LinkedList* initlist(){
    LinkedList* L = (LinkedList*)malloc(sizeof(LinkedList));
    L->head = NULL;
    L->tail = NULL;
    L->size = 0;
    return L;
}
void pushBack(LinkedList* L, int val){
    // make a node and set the value to be val
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = val;
    // check for if its a new list
    if (L->head == NULL){
        L->head = n;
        L->tail = n;
    } else {
        // set tail->next to n
        L->tail->next = n;
        // set tail->next
        L->tail= n;
    }
    L->size++;
}
void pushFront(LinkedList* L, int val){
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = val;
    if (L->head == NULL){
        L->head = n;
        L->tail = n;
        L->size++;
    } else {
        n->next = L->head;
        L->head = n;
        L->size++;
    }
}
int popFront(LinkedList* L){
    if (L->size == 0){
        return NULL;
    } else if(L->head == L->tail) {
        int val = L->head->next;
        L->head = NULL;
        L->tail = NULL;
        L->size--;
        return val;
    } else {
        int val = L->head->val;
        L->head = L->head->next;
        L->size--;
        return val;
    }
}
int popBack(LinkedList* L){
    if (L->head == NULL){
        return 0;
    }
    Node* cur = L->head;
    int val = L->tail->val;
    while(cur->next->next != NULL){
        cur = cur->next;
    }
    L->tail = cur;
    L->size--;
    return val;
}
void FreeList(LinkedList* L){
    Node* n = L->head;
    while(n != NULL){
        Node* tmp = n->next;
        free(n);
        n = tmp;
    }
    free(L);
}
main(){
    LinkedList* L = initlist();
    pushBack(L, 10);
    pushFront(L, 42);
    pushBack(L, 69);
    pushFront(L, 420);
    printf("%d\n",popBack(L));
    printf("%d\n",popBack(L));
    printf("%d\n",popBack(L));
    printf("%d\n",popBack(L));
    FreeList(L);

}