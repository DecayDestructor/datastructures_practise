// Conversion of Infix expression to prefix expression using stack
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 1000
struct stack
{
    int top;
    char items[SIZE];
};

// Function to initialize stack

struct stack *initStack()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    return s;
}

// Function to push an element to stack

void push(struct stack *s, char item)
{
    if (s->top >= SIZE - 1)
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

char pop(struct stack *s)
{
    if (s->top < 0)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    else
    {
        return s->items[s->top--];
    }
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

int main()
{
    char str[100];
    printf("Enter an infix expression: ");
    scanf("%s", str);
    struct stack *s = initStack();
    int len = strlen(str);
    printf("%d", len);
    char prefix[100];
    int j = len;
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            prefix[--j] = str[i];
            // printf("%c\n", str[i);
            printf("%c\n", prefix[j]);
        }
        else if (str[i] == ')')
        {
            printf("Added bracket\n");
            push(s, str[i]);
        }
        else if (str[i] == '(')
        {
            printf("Removed bracket\n");
            while (s->top != -1 && s->items[s->top] != ')')
            {
                printf("popping %c\n", s->items[s->top]);
                prefix[--j] = pop(s);
                printf("%c\n", prefix[j]);
            }
            pop(s);
        }
        else
        {
            while (s->top != -1 && precedence(str[i]) < precedence(s->items[s->top]))
            {
                // show popped characters
                printf("popping %c\n", s->items[s->top]);
                prefix[--j] = pop(s);
                printf("%c\n", prefix[j]);
            }
            push(s, str[i]);
            // show the pushed character
            printf("%c\n", str[i]);
        }
        }
    while (s->top != -1)
    {
        prefix[--j] = pop(s);
    }
    prefix[len] = '\0';
    printf("Prefix expression: %s\n", &prefix[j]);
    return 0;
}