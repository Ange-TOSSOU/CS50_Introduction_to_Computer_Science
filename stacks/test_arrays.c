#include <stdio.h>

#include "lists_based.h"

int main(void)
{
    Stack *head = NULL;

    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 7);
    head = push(head, 11);
    head = push(head, 11);

    Stack *cur = head;
    while (cur != NULL)
    {
        printf("%i\n", cur->value);
        cur = cur->next;
    }

    printf("\n");

    find(head, 10) ? printf("Found the value %i\n", 10) : printf("Not found the value %i\n", 10);
    find(head, 11) ? printf("Found the value %i\n", 11) : printf("Not found the value %i\n", 11);

    head = destroy(head);

    return 0;
}
