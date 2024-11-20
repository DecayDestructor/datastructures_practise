#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Stack
{
    int top;
    struct Node **node;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Stack *initialiseStack()
{
    struct Stack *stk = (struct Stack *)malloc(sizeof(struct Stack));
    stk->top = -1;
}