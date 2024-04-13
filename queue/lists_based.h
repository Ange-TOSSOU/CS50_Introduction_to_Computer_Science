#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int value;
    struct stack *next;
} Stack;

Stack *create(int value);
int find(Stack *head, int value);
Stack *push(Stack *head, int value);
Stack *destroy(Stack *head);
