#include "singly.h"

Node* create(int value)
{
    Node* n = malloc(sizeof(Node));

    if (n != NULL)
    {
        n->value = value;
        n->next = NULL;
    }

    return n;
}

int find(Node* head, int value)
{
    Node* current = head;

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

Node* insert(Node* head, int value)
{}
