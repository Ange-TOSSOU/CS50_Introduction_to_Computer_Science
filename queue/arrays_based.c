#include "arrays_based.h"

Stack *create(int capacity)
{
    if (capacity <= 0)
    {
        return NULL;
    }

    Stack *s = malloc(sizeof(Stack));
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

int push(Stack *s, int value)
{
    if (s == NULL || s->top + 1 > s->capacity)
    {
        return 0;
    }

    s->array[s->top++] = value;

    return 1;
}

int pop(Stack *s)
{
    if (s == NULL || s->top == 0)
    {
        return 0;
    }

    return s->array[s->top--];
}

Stack *destroy(Stack *s)
{
    if (s != NULL)
    {
        free(s->array);
        free(s);
    }

    return NULL;
}
