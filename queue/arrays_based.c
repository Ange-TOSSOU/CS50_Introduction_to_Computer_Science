#include "arrays_based.h"

Queue *create(int capacity)
{
    if (capacity <= 0)
    {
        return NULL;
    }

    Queue *s = malloc(sizeof(Queue));
    if (s == NULL)
    {
        return NULL;
    }

    s->array = malloc(capacity * sizeof(int));
    if (s->array == NULL)
    {
        free(s);
        return NULL;
    }
    s->capacity = capacity;
    s->top = 0;

    return s;
}

int enqueue(Queue *s, int value)
{
    if (s == NULL || s->top + 1 > s->capacity)
    {
        return 0;
    }

    s->array[s->top++] = value;

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
