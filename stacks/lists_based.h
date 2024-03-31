#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int value;
    struct node *next;
} Stack;

Node *create(int value);
int find(Node *head, int value);
Node *insert(Node *head, int value);
Node *destroy(Node *head);
