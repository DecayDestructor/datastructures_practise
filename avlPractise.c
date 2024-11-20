// C program to implement the avl tree
#include <stdio.h>
#include <stdlib.h>

// AVL Tree node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// Function to get height of the node
int getHeight(struct Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

// Function to create a new node
struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially added at leaf
    return node;
}

// Utility function to get the maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Function to get balance factor of a node
int getBalanceFactor(struct Node *n)
{
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

void

    // Function to perform preorder traversal of AVL tree
    void
    inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Main function
int main()
{
    struct Node *root = NULL;

    // Inserting nodes
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    // Print preorder traversal of the AVL tree
    printf("Inorder traversal of AVL tree: ");
    inOrder(root);

    return 0;
}