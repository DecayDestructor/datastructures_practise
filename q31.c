#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *node, struct Node *head)
{
    if (!head)
    {
        return node;
    }
    if (node->val >= head->val)
    {
        head->right = insertNode(node, head->right);
    }
    else
    {
        head->left = insertNode(node, head->left);
    }
    return head;
}

struct Node *leaves(struct Node *root, struct Node *child, int val)
{
    if (child == NULL)
    {
        return NULL;
    }
    else if (child->val == val)
    {
        return root;
    }
    else if (val >= child->val)
    {
        return leaves(child, child->right, val);
    }
    else
    {
        return leaves(child, child->left, val);
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    struct Node *root;
    for (int i = 0; i < n; i++)
    {
        int val;
        printf("Enter value of node %d\n", i + 1);
        scanf("%d", &val);
        struct Node *temp = createNode(val);
        if (i == 0)
        {
            root = temp;
        }
        else
        {
            insertNode(temp, root);
        }
    }
    int d;
    printf("Enter the node\n");
    scanf("%d", &d);
    printf("The predecessor of node  is %d\n", leaves(root, root, d)->val);
}
