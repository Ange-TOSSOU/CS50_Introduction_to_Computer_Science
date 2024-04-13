#include "lists_based.h"

Queue *create(int value)
{
    Queue *n = malloc(sizeof(Queue));

    if (n != NULL)
    {
        n->value = value;
        n->next = NULL;
    }

    return n;
}

int find(Queue *head, int value)
{
    Queue *current = head;

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

Queue *push(Queue *head, int value)
{
    Queue *n = create(value);

    if (n == NULL)
    {
        return head;
    }

    n->next = head;

    return n;
}

int pop(Queue *head)
{
    if (head == NULL)
    {
        return 0;
    }

    Queue *current = head;
    int value = current->value;
    head = head->next;
    free(current);

    return value;
}

Queue *destroy(Queue *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    destroy(head->next);
    free(head);

    return NULL;
}
