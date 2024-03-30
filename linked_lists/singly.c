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
