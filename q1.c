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

void initliaseStack(struct Stack *stk)
{
    stk->top = -1;
    stk->arr = (char *)malloc(sizeof(char) * size);
    // stk->sizeStack = size;
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

int precedence(char op)
{
    switch (op)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

int main()
{
    struct Stack *stk = (struct Stack *)malloc(sizeof(struct Stack));
    initliaseStack(stk);

    char str[100];
    printf("Enter an infix expression: ");
    scanf("%s", str);
    char ans[100];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            ans[j++] = str[i];
        }
        else if (str[i] == '(')
        {
            push(stk, str[i]);
        }
        else if (str[i] == ')')
        {
            while (stk->top != -1 && top(stk) != '(')
            {
                ans[j++] = top(stk);
                pop(stk);
            }
            pop(stk);
        }
        else
        {
            while (stk->top != -1 && (precedence(top(stk)) <= precedence(str[i])))
            {
                ans[j++] = top(stk);
                pop(stk);
            }
            push(stk, str[i]);
        }
    }
    while (stk->top != -1)
    {
        if (stk->arr[stk->top] != '(' && stk->arr[stk->top] != ')')
        {
            ans[j++] = stk->arr[stk->top];
        }
        pop(stk);
    }
    ans[j] = '\0';
    printf("Postfix expression: %s\n", ans);
    free(stk->arr);
    free(stk);
    return 0;
}