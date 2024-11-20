#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    // node->prev = NULL;
    return node;
}

void displayList(struct Node *head)
{
    struct Node *curr = head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

struct Node *reverseList(struct Node *head)
{
    struct Node *curr = head;
    struct Node *prev = NULL;
    struct Node *after = curr->next;
    while (curr != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = after;
        if (after != NULL)
            after = after->next;
    }
    return prev;
}

int main()
{
    int a, b;
    printf("Enter number of digits in op1 and op2\n");
    scanf("%d %d", &a, &b);
    struct Node *head1, *head2;
    struct Node *prev;
    printf("Enter values for op1\n");
    for (int i = 0; i < a; i++)
    {
        int val;
        scanf("%d", &val);
        struct Node *temp = createNode(val);
        if (i == 0)
        {
            head1 = temp;
            prev = head1;
        }
        else
        {
            prev->next = temp;
            prev = temp;
        }
    }
    printf("Enter values for op2\n");
    for (int i = 0; i < b; i++)
    {
        int val;
        scanf("%d", &val);
        struct Node *temp = createNode(val);
        if (i == 0)
        {
            head2 = temp;
            prev = head2;
        }
        else
        {
            prev->next = temp;
            prev = temp;
        }
    }
    // displayList(head1);
    // displayList(head2);
    head1 = reverseList(head1);
    head2 = reverseList(head2);
    // displayList(head1);
    // displayList(head2);
    bool carry = false;
    struct Node *curr1 = head1, *curr2 = head2;
    int index = 0;
    struct Node *answer;
    while (curr2 != NULL && curr1 != NULL)
    {
        int val = curr1->data + curr2->data;
        if (carry)
        {
            val++;
            carry = false;
        }
        int newVal = val % 10;
        int newCarry = val / 10;
        if (newCarry > 0)
        {
            carry = true;
        }
        struct Node *temp = createNode(newVal);
        if (index == 0)
        {
            answer = temp;
            prev = answer;
        }
        else
        {
            prev->next = temp;
            prev = temp;
        }
        index++;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    if (curr1 != NULL)
    {
        prev->next = curr1;
    }
    else if (curr2 != NULL)
    {
        prev->next = curr2;
    }
    while (carry)
    {
        if (prev->next == NULL)
        {
            struct Node *temp = createNode(1);
            prev->next = temp;
            prev = prev->next;
            break;
        }
        prev = prev->next;
        prev->data++;
        // val++;
        int val = prev->data;
        int setCarry = val / 10;
        prev->data = prev->data / 10;
        if (setCarry > 0)
        {
            carry = true;
        }
        else
        {
            carry = false;
        }
    }
    displayList(answer);
    answer = reverseList(answer);
    displayList(answer);
    free(head1);
    free(head2);
    return 0;
}