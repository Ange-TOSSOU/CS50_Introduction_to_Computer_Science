#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int value;
    struct stack *next;
} Stack;

Stack *create(int value);
int find(Stack *s, int value);
Stack *push(Stack *s, int value);
Stack *push(Stack *s, int value);
Stack *destroy(Stack *s);
