// Implement univariate Polynomial addition using linked lists. A univariate polynomial
// should be represented in the decreasing order of its coefficient.
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
struct Node
{
    int data;
    struct Node *next;
    int power;
};

struct Node *createNode(int data, int power)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    int pow1;
    printf("Enter the highest power of polynomial\n");
    scanf("%d", &pow1);
    int pow2 = pow1;
    struct Node *poly1 = NULL, *poly2 = NULL, *polySum = NULL;
    struct Node *prev = NULL;
    for (int i = pow1; i >= 0; i--)
    {
        int coeff;
        printf("Enter coefficient of x^%d for polynomial 1: ", i);
        scanf("%d", &coeff);
        struct Node *newNode = createNode(coeff, i);
        if (i == pow1)
        {
            poly1 = newNode;
            prev = poly1;
            // printf("%d^%d", prev->data, prev->power);
        }
        else
        {
            // printf("%d^%d", newNode->data, newNode->power);
            // printf("%d^%d", prev->data, prev->power);
            prev->next = newNode;
            prev = newNode;
            // printf("%d^%d", prev->data, prev->power);
        }
    }
    for (int i = pow2; i >= 0; i--)
    {
        int coeff;
        printf("Enter coefficient of x^%d for polynomial 2: ", i);
        scanf("%d", &coeff);
        struct Node *newNode = createNode(coeff, i);
        if (i == pow2)
        {
            poly2 = newNode;
            prev = poly2;
        }
        else
        {
            prev->next = newNode;
            prev = newNode;
        }
    }
    printf("Polynomial 1: ");
    struct Node *temp = poly1;
    while (temp != NULL)
    {
        printf("%dx^%d ", temp->data, temp->power);
        temp = temp->next;
    }
    printf("\nPolynomial 2: ");
    temp = poly2;
    while (temp != NULL)
    {
        printf("%dx^%d ", temp->data, temp->power);
        temp = temp->next;
    }
    struct Node *temp1 = poly1;
    struct Node *temp2 = poly2;
    prev = polySum;
    int index = 0;
    while (temp1 != NULL)
    {
        struct Node *newNode = createNode(temp1->data + temp2->data, temp1->power);
        if (index == 0)
        {
            polySum = newNode;
            prev = polySum;
        }
        else
        {
            prev->next = newNode;
            prev = newNode;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
        index++;
    }
    temp = polySum;
    printf("\n");
    while (temp != NULL)
    {
        printf("%dx^%d ", temp->data, temp->power);
        temp = temp->next;
    }
    free(temp);
    free(temp1);
    free(temp2);
    free(prev);
    free(poly1);
    free(poly2);
    free(polySum);
    return 0;
}
