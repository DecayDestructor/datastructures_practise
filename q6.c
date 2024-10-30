// Evaluation of Prefix expression using Stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct Stack
{
    int top;
    int arr[SIZE];
    /* data */
};

struct Stack *initialise()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->top = -1;
    return s;
}

int top(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}

void push(struct Stack *s, int value)
{
    if (s->top >= SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++s->top] = value;
}

int pop(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

int main()
{
    char prefix[SIZE];
    printf("Enter prefix expression: ");
    scanf("%s", prefix);
    struct Stack *s = initialise();
    int len = strlen(prefix);
    for (int i = len - 1; i >= 0; i--)
    {
        char ch = prefix[i];
        if (ch >= '0' && ch <= '9')
        {
            push(s, ch - '0');
        }
        else
        {
            int op1 = pop(s);
            int op2 = pop(s);
            switch (ch)
            {
            case '+':
                push(s, op1 + op2);
                break;
            case '-':
                push(s, op1 - op2);
                break;
            case '*':
                push(s, op1 * op2);
                break;
            case '/':
                push(s, op1 / op2);
                break;
            }
        }
    }
    printf("Result: %d\n", top(s));
}
