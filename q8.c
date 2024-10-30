// Given a singly linked list, determine if it's a palindrome. Return 1 or 0 denoting if it's a
// palindrome or not

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    int top;
    int size;
    struct Node **items;
};

// Function to create a new node

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// initialise stack

struct Stack *createStack(int size)
{

    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->items = (struct Node **)malloc(size * sizeof(struct Node));
    for (int i = 0; i < size; i++)
    {
        stack->items[i] = (struct Node *)malloc(size * sizeof(struct Node));
    }
    return stack;
}

// Function to push an element to stack

void push(struct Stack *stack, struct Node *newNode)
{
    if (stack->top == stack->size - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = newNode;
    printf("Pushed %d to stack\n", stack->items[stack->top]->data);
}

// Function to pop an element from stack

struct Node *pop(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack Underflow\n");
        return NULL;
    }
    return stack->items[stack->top--];
}

// Function to check if a linked list is palindrome
int main()
{
    int n;
    printf("Enter the size of the linked list");
    scanf("%d", &n);
    struct Node *head = NULL;
    struct Node *prev = NULL;
    struct Stack *stack = createStack(n);
    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        struct Node *newNode = createNode(data);
        push(stack, newNode);
        if (i == 0)
        {
            head = newNode;
            prev = newNode;
        }
        else
        {
            prev->next = newNode;
            prev = newNode;
        }
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    int isPalindrome = 1;
    temp = head;
    while (temp != NULL)
    {
        struct Node *popped = pop(stack);
        if (popped->data != temp->data)
        {
            isPalindrome = 0;
            break;
        }
        temp = temp->next;
    }
    printf("%d\n", isPalindrome);
    free(temp);
    free(head);
    free(stack);
    return 0;
}