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

    q->array[q->top++] = value;

    return 1;
}

int dequeue(Queue *s)
{
    if (s == NULL || s->top == 0)
    {
        return 0;
    }

    return s->array[s->top--];
}

Queue *destroy(Queue *s)
{
    if (s != NULL)
    {
        free(s->array);
        free(s);
    }

    return NULL;
}
