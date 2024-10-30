// Evaluation of Postfix expression using Stack

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack
{
    int top;
    int items[100];
};

struct Stack *initialiseStack()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to push an element onto stack

void push(struct Stack *s, int item)
{
    if (s->top >= 99)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        s->items[++s->top] = item;
    }
}

// Function to pop an element from stack

int pop(struct Stack *s)
{
    if (s->top < 0)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return s->items[s->top--];
    }
}

int top(struct Stack *s)
{
    return s->items[s->top];
}

int main()
{
    char postfix[100];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    int len = strlen(postfix);
    struct Stack *s = initialiseStack();
    for (int i = 0; i < len; i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            push(s, postfix[i] - '0');
        }
        else
        {
            int op1 = pop(s);
            int op2 = pop(s);
            int result;
            switch (postfix[i])
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op2 - op1;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op2 / op1;
                break;
            }
            push(s, result);
        }
    }
    printf("Result: %d\n", top(s));
}