#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 1000
struct Stack
{
    int top;
    char *arr;
    // int sizeStack;
};

struct Stack *initialiseStack()
{
    struct Stack *stk = (struct Stack *)malloc(sizeof(struct Stack));
    stk->top = -1;
    stk->arr = (char *)malloc(sizeof(char) * size);
}

void push(struct Stack *stk, char val)
{
    if (stk->top == size - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stk->top++;
    stk->arr[stk->top] = val;
}

void pop(struct Stack *stk)
{
    if (stk->top < 0)
    {
        printf("Stack underflow\n");
        return;
    }
    stk->top--;
}
char top(struct Stack *stk)
{
    if (stk->top < 0)
    {
        printf("Stack underflow\n");
        return '\0';
    }
    return stk->arr[stk->top];
}
