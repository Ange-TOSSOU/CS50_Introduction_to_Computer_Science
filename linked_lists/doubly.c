#include "doubly.h"

Node *create(int value)
{
    Node *n = malloc(sizeof(Node));

    if (n != NULL)
    {
        n->value = value;
        n->prev = n->next = NULL;
    }

    return n;
}

int find(Node *head, int value)
{
    Node *current = head;

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

Node *insert(Node *head, int value)
{
    Node *n = create(value);

    if (n == NULL)
    {
        return head;
    }

    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }

    return n;
}

Node *delete(Node *head, int value)
{
    Node *current = head;

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
        if (current->prev != NULL)
        {
            current->prev->next = NULL;
        }
        else
        {
            head = NULL;
        }
    }
    else
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    free(current);

    return head;
}

Node *destroy(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    destroy(head->next);
    free(head);

    return NULL;
}
