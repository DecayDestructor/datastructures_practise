#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node
{
    int src;
    struct Node *next;
};

struct Graph
{
    int vertices;
    struct Node **adjLists;
};
struct Graph *initialiseGraph(int n)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = n + 1;
    graph->adjLists = (struct Node **)malloc((n + 1) * sizeof(struct Node));
    for (int i = 1; i <= n; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}
void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

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
