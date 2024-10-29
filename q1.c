#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000

struct stack
{
    char arr[SIZE];
    int top;
};

void pop(struct stack *stk)
{
    if (stk->top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    else
    {
        stk->top--;
    }
}

void push(struct stack *stk, char ch)
{
    if (stk->top == SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stk->arr[++stk->top] = ch;
}

struct stack *initialize()
{
    struct stack *stk = (struct stack *)malloc(sizeof(struct stack));
    stk->top = -1;
    return stk;
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
    struct stack *stk = initialize();
    char str[100];
    printf("Enter an infix expression: ");
    scanf("%s", str);
    char ans[100];
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        // infix to postfix
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
            while (stk->top != -1 && stk->arr[stk->top] != '(')
            {
                ans[j++] = stk->arr[stk->top];
                pop(stk);
            }
            pop(stk); // Pop '('
        }
        else
        {
            while (stk->top != -1 && precedence(stk->arr[stk->top]) >= precedence(str[i]))
            {
                ans[j++] = stk->arr[stk->top];
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
    return 0;
}
