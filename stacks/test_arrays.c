#include <stdio.h>

#include "arrays_based.h"

int main(void)
{
    Stack *s = create(10);

    push(s, 1);
    push(s, 2);
    push(s, 7);
    push(s, 11);
    push(s, 11);

    for (int i = s->top - 1; i >= 0 ; i--)
    {
        printf("%i\n", s->array[i]);
    }

    s = destroy(s);

    return 0;
}
