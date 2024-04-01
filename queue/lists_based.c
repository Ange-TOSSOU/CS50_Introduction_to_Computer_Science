#include "lists_based.h"

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

int find(Stack *head, int value)
{
    Stack *current = head;

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

Stack *push(Stack *head, int value)
{
    Stack *n = create(value);

    if (n == NULL)
    {
        return head;
    }

    n->next = head;

    return n;
}

int pop(Stack *head)
{
    if (head == NULL)
    {
        return 0;
    }

    Stack *current = head;
    int value = current->value;
    head = head->next;
    free(current);

    return value;
}

Stack *destroy(Stack *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    destroy(head->next);
    free(head);

    return NULL;
}
