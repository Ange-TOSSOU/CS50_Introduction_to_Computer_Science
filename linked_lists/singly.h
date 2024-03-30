#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
}
Node;

Node* create(int value);
int find(Node* head, int value);
Node* insert(Node* head, int value);
