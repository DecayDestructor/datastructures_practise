// Implement the following operations on doubly linked lists:
// a.Insert(after position)
//     b.sort the list
//     c.display

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    node->prev = NULL;
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

struct Node *split(struct Node *head)
{
    if (head->next == NULL)
    {
        return head;
    }
    struct Node *fast = head;
    struct Node *slow = head;
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct Node *temp = slow->next;
    slow->next = NULL;
    if (temp != NULL)
    {
        temp->prev = NULL;
    }
    return temp;
}

struct Node *merge(struct Node *left, struct Node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    if (left->data <= right->data)
    {
        left->next = merge(left->next, right);
        if (left->next != NULL)
        {
            left->next->prev = left;
        }
        left->prev = NULL;
        return left;
    }
    else
    {
        right->next = merge(left, right->next);
        if (right->next != NULL)
        {
            right->next->prev = right;
        }
        right->prev = NULL;
        return right;
    }
}

struct Node *mergeSort(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct Node *second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);
    return merge(head, second);
}
int main()
{
    struct Node *head = createNode(10);
    head->next = createNode(8);
    head->next->prev = head;
    head->next->next = createNode(5);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(2);
    head->next->next->next->prev = head->next->next;
    head = mergeSort(head);
    displayList(head);
    return 0;
}