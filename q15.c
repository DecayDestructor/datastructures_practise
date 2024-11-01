// Write a program to construct a binary search tree and traverse it with all methods that uses
// recursion.

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
}

struct Node *insertNode(struct Node *node, struct Node *head)
{
    if (head == NULL)
    {
        return node;
    }
    if (node->val < head->val)
    {
        head->left = insertNode(node, head->left);
    }
    else
    {
        head->right = insertNode(node, head->right);
    }
    return head;
}

void postOrder(struct Node *node)
{
    if (node == NULL)
        return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->val);
}
void inOrder(struct Node *node)
{
    if (node == NULL)
        return;
    postOrder(node->left);
    printf("%d ", node->val);
    postOrder(node->right);
}
void preOrder(struct Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->val);
    postOrder(node->left);
    postOrder(node->right);
}

int main()
{

    int n;
    scanf("%d", &n);
    int temp = n;
    struct Node *root = NULL;
    while (n--)
    {
        printf("enter the value for node %d", temp - n);
        int val;
        scanf("%d", &val);
        struct Node *newNode = createNode(val);
        if (temp - n == 1)
        {
            root = newNode;
        }
        else
        {
            insertNode(newNode, root);
        }
    }
    postOrder(root);
    return 0;
}