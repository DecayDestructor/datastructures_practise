#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node
{
    int src;
    struct Node *next;
};

struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->src = val;
    newNode->next = NULL;
    return newNode;
}

struct Queue
{
    int front, rear;
    int *arr;
    int size;
};
struct Queue *initialiseQueue(int size)
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->rear = -1;
    q->front = 0;
    q->arr = (int *)malloc(100 * sizeof(int));
    q->size = size;
    return q;
}
bool isEmpty(struct Queue *q)
{
    return q->rear < q->front;
}
bool isFull(struct Queue *q)
{
    return q->rear == 100 - 1;
}
void push(struct Queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    q->arr[++q->rear] = val;
}
void pop(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    q->front++;
}
int top(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Underflow error\n");
        return -1;
    }
    return q->arr[q->front];
}
void bfs(int **adjMat, int start, int size)
{
    int *visited = (int *)malloc(sizeof(int) * (size + 1));
    for (int i = 1; i <= size; i++)
    {
        visited[i] = 0;
    }
    struct Queue *q = initialiseQueue(size);
    push(q, start);
    while (!isEmpty(q))
    {
        int val = top(q);
        printf("%d\n", val);
        pop(q);
        visited[val] = 1;
        for (int i = 1; i <= size; i++)
        {
            if (adjMat[val][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                push(q, i);
            }
        }
    }
    return;
}
int main()
{
    int n;
    printf("Enter the total number of nodes\n");
    scanf("%d", &n);

    // Allocate memory for adjacency matrix
    int **adjMat = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
    {
        adjMat[i] = (int *)malloc((n + 1) * sizeof(int)); // Allocate row-wise
    }

    // Initialize the adjacency matrix
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            adjMat[i][j] = 0;
        }
    }
    for (int u = 1; u <= n; u++)
    {
        int e;
        printf("Enter the number of edges for node %d\n", u);
        scanf("%d", &e);
        for (int j = 1; j <= e; j++)
        {
            int v;
            printf("Enter the endpoint of edge %d: ", j);
            scanf("%d", &v);
            adjMat[u][v] = 1; // Mark the edge in the adjacency matrix
            adjMat[v][u] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adjMat[i][j] == 1)
                printf("%d %d\n", i, j);
        }
    }
    bfs(adjMat, 1, n + 1);
}
