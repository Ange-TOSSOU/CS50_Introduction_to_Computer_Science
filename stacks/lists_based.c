#include "singly.h"

Stack *create(int value)
{
    Stack *n = malloc(sizeof(Stack));

    if (n != NULL)
    {
        n->value = value;
        n->next = NULL;
    }

    return n;
}

int find(Stack *s, int value)
{
    Stack *current = s;

    while (current != NULL)
    {
        if (current->value == value)
        {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

Stack *push(Stack *s, int value)
{
    Stack *n = create(value);

    if (n == NULL)
    {
        return s;
    }

    n->next = s;

    return n;
}

int pop(Stack *s)
{
    Stack *current = s;

    while (current != NULL)
    {
        if (current->value == value)
        {
            break;
        }
        current = current->next;
    }

    if (current == NULL)
    {
        return s;
    }

    if (current->prev == NULL)
    {
        if (current->next != NULL)
        {
            current->next->prev = NULL;
        }
        s = current->next;
    }
    else if (current->next == NULL)
    {
        // We already know that current->prev != NULL
        current->prev->next = NULL;
    }
    else
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    free(current);

    return s;
}

Stack *destroy(Stack *s)
{
    if (s == NULL)
    {
        return NULL;
    }

    destroy(s->next);
    free(s);

    return NULL;
}
