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

int leaves(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int maxi = 0;
    int leftCount = leaves(root->left);
    int rightCount = leaves(root->right);
    if (leftCount > rightCount)
    {
        maxi = leftCount;
    }
    else
    {
        maxi = rightCount;
    }
    return maxi + 1;
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
    printf("The height of tree  is %d", leaves(root));
}
