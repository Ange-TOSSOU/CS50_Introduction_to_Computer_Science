#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int capacity;
    int front;
    int size;
} Queue;

Queue *create(int capacity);
int enqueue(Queue *s, int value);
int dequeue(Queue *s);
Queue *destroy(Queue *s);
