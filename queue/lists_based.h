#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int value;
    struct queue *next;
} Queue;

Queue *create(int value);
int find(Queue *head, int value);
Queue *push(Queue *head, int value);
Queue *destroy(Queue *head);
