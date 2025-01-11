#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int size;
    unsigned capacity;
    int* numbers;
}Stack;

Stack* makeStack(unsigned capacity){
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->capacity = capacity;
    s->size = 0;
    s->numbers = (int*) malloc(sizeof(int) * capacity);
    return s;
}

void freeStack(Stack* s)
{
    free(s->numbers);
    free(s);
}

void resize(Stack* stack)
{
    stack->capacity *= 2;
    stack->numbers = (int*) realloc(stack->numbers, sizeof(int) * stack->capacity);
}

void push(Stack* stack, int input)
{
    if (stack->capacity == stack->size)
    {
        resize(stack);
    }
    stack->numbers[stack->size] = input;
    stack->size += 1;
}

int pop(Stack* stack)
{
    if (stack->size == 0)
    {
        return -1;
    }
    int val = stack->numbers[stack->size - 1];
    stack->size--;
    return val;
}

int main()
{
    Stack* s = makeStack(3);
    push(s, 1);
    push(s, 42);
    push(s, 69);
    push(s, 7331);
    while (s->size > 0)
    {
        printf("%d\n", pop(s));
    }
    freeStack(s);
    return 0;
}