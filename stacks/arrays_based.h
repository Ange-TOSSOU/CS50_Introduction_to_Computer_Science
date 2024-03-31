#include <stdio.h>

#define CAPACITY 20

typedef struct
{
    int array[CAPACITY];
    int top;
} Stack;

void push(Stack *s, int value);
int pop(Stack *s);
