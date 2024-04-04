#include "arrays_based.h"

Queue *create(int capacity)
{
    if (capacity <= 0)
    {
        return NULL;
    }

    Queue *q = malloc(sizeof(Queue));
    if (q == NULL)
    {
        return NULL;
    }

    q->array = malloc(capacity * sizeof(int));
    if (q->array == NULL)
    {
        free(q);
        return NULL;
    }
    q->capacity = capacity;
    q->front = q->size = 0;

    return q;
}

int enqueue(Queue *q, int value)
{
    if (q == NULL || q->size == q->capacity)
    {
        return 0;
    }

    q->array[(q->front + q->size) % q->capacity] = value;
    q->size++;

    return 1;
}

int dequeue(Queue *q)
{
    if (q == NULL || q->size == 0)
    {
        return 0;
    }

    int value = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;

    return value;
}

Queue *destroy(Queue *q)
{
    if (s != NULL)
    {
        free(q->array);
        free(q);
    }

    return NULL;
}