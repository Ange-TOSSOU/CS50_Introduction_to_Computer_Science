#include <stdio.h>

#include "singly.h"

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
    }

    
    return 0;
}
