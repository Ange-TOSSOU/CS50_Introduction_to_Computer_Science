#include <stdio.h>

#include "doubly.h"

int main(void)
{
    Node *list = NULL, *cur = NULL;

    list = insert(list, 1);
    list = insert(list, 2);
    list = insert(list, 7);
    list = insert(list, 11);
    list = insert(list, 11);

    cur = list;
    while (cur != NULL)
    {
        printf("%i\n", cur->value);
        cur = cur->next;
    }

    printf("\n");

    find(list, 10) ? printf("Found the value %i\n", 10) : printf("Not found the value %i\n", 10);
    find(list, 11) ? printf("Found the value %i\n", 11) : printf("Not found the value %i\n", 11);

    printf("\n");

    list = delete(list, 1);
    printf("Delete the value %i\n", 1);
    cur = list;
    while (cur != NULL)
    {
        printf("%i\n", cur->value);
        cur = cur->next;
    }

    printf("\n");

    list = delete(list, 11);
    printf("Delete the value %i\n", 11);
    cur = list;
    while (cur != NULL)
    {
        printf("%i\n", cur->value);
        cur = cur->next;
    }

    list = destroy(list);

    return 0;
}
