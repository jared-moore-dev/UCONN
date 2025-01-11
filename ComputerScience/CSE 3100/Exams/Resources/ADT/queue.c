#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int front, back, size;
    unsigned capacity;
    int* array;
}Queue;
// Create a Queue
Queue* createQueue(unsigned capacity){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;

    queue->back = capacity-1;
    queue->array = (int*)malloc(sizeof(int)*queue->capacity);
    return queue;
}
// test if queue is full
int isFull(Queue* queue){
    return (queue->size == queue->capacity);
}
// Returns if Queue is empty
int isEmpty(Queue* queue){
    return (queue->size == 0);
}
// Adds something to the queue
void enqueue(Queue* queue, int val){
    if (isFull(queue)) return;
    queue->back = (queue->back +1) % queue->capacity;
    queue->array[queue->back] = val;
    queue->size += 1;
    // printf("%d enqueued to queue\n", val);
}
// removes something from the queue
int dequeue(Queue* queue){
    if (isEmpty(queue)) return NULL;
    // set a temp variable to shnagg your first item
    int val = queue->array[queue->front];
    // set the front to be the front +1
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size -= 1;
    return val;
}
int front(Queue* queue){
    if (isEmpty(queue)) return NULL;
    return queue->array[queue->front];
}
int back(Queue* queue){
    if (isEmpty(queue)) return NULL;
    return queue->array[queue->back];
}

int main() {
    Queue* myqueue = createQueue(1000);
    // do things to it
    enqueue(myqueue, 10);
    enqueue(myqueue, 45);
    enqueue(myqueue, 32);
    enqueue(myqueue, 69);

    int val1 = dequeue(myqueue);
    printf("%d was the first item enqueued\n", val1);
    printf("%d\n", dequeue(myqueue));
    printf("Front (first item in the queue) item is %d\n", front(myqueue));
    printf("Rear (last item in the queue) item is %d\n", back(myqueue));
    return 0;
}
