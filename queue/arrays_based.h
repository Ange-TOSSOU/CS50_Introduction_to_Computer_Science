#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int capacity;
    int top;
} Queue;

Queue *create(int capacity);
int push(Queue *s, int value);
int pop(Queue *s);
Queue *destroy(Queue *s);
