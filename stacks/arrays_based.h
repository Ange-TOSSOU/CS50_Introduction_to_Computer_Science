#include <stdio.h>

typedef struct
{
    int *array;
    int capacity;
    int top;
} Stack;

Stack *create(int capacity);
int push(Stack *s, int value);
int pop(Stack *s);
