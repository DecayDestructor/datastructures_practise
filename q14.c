// Given  a  linked  list  and  a  value  x,  partition  it  such  that  all  nodes  less  than  x  come  before
// nodes greater than or equal to x.You should preserve the original relative order of the nodes
//   in each of the two partitions

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

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
    return;
}

int main()
{
    int n;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    struct Node *head = NULL;
    struct Node *prev = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Enter the data for node %d\n", i + 1);
        scanf("%d", &data);
        struct Node *newNode = createNode(data);
        if (i == 0)
        {
            head = newNode;
            prev = head;
        }
        else
        {
            prev->next = newNode;
            prev = prev->next;
        }
    }
    displayList(head);
    int x;
    printf("Enter the split point\n");
    scanf("%d", &x);
    struct Node *middle;
    struct Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == x)
        {
            middle = curr;
            break;
        }
        curr = curr->next;
    }
    curr = head;
    struct Node *smallHead = NULL;
    struct Node *smallTail = NULL;
    struct Node *largeHead = NULL;
    struct Node *largeTail = NULL;
    while (curr != NULL)
    {
        if (curr->data < x)
        {
            if (smallHead == NULL)
            {
                smallHead = curr;
                smallTail = curr;
            }
            else
            {
                smallTail->next = curr;
                smallTail = smallTail->next;
            }
        }
        else if (curr->data > x)
        {
            if (largeHead == NULL)
            {
                largeHead = curr;
                largeTail = curr;
            }
            else
            {
                largeTail->next = curr;
                largeTail = largeTail->next;
            }
        }
        curr = curr->next;
    }

    if (smallTail != NULL)
    {
        smallTail->next = middle;
        middle->next = largeHead;
    }
    if (largeTail != NULL)
    {
        largeTail->next = NULL;
    }
    displayList(smallHead);
}