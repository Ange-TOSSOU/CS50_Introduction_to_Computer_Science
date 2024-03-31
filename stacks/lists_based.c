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

Stack *insert(Stack *head, int value)
{
    Stack *n = create(value);

    if (n == NULL)
    {
        return head;
    }

    n->next = head;

    return n;
}

/*int pop(Stack *head)
{
    Stack *current = head;

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
        return head;
    }

    if (current->prev == NULL)
    {
        if (current->next != NULL)
        {
            current->next->prev = NULL;
        }
        head = current->next;
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

    return head;
}*/

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
