#include <stdio.h>

#include "lists_based.h"

int main(void)
{
    Node *list = NULL;

    list = insert(list, 1);
    list = insert(list, 2);
    list = insert(list, 7);
    list = insert(list, 11);
    list = insert(list, 11);

    Node *cur = list;
    while (cur != NULL)
    {
        printf("%i\n", cur->value);
        cur = cur->next;
    }

    printf("\n");

    find(list, 10) ? printf("Found the value %i\n", 10) : printf("Not found the value %i\n", 10);
    find(list, 11) ? printf("Found the value %i\n", 11) : printf("Not found the value %i\n", 11);

    list = destroy(list);

    return 0;
}
