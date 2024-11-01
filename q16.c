#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front;
    int rear;
    int *arr;
    int size;
};

struct Queue *initialiseQueue(int n)
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = 0;
    q->rear = -1;
    q->arr = (int *)malloc(n * sizeof(int));
    q->size = n;
    return q;
}

void push(struct Queue *q, int val)
{
    if (q->rear == q->size - 1) // Corrected the condition to check if full
    {
        printf("Full\n");
        return;
    }
    q->arr[++q->rear] = val;
}

int top(struct Queue *q)
{
    if (q->rear < q->front)
    {
        printf("Empty queue\n");
        return -1; // Indicating an error
    }
    return q->arr[q->front];
}

void pop(struct Queue *q)
{
    if (q->rear < q->front)
    {
        printf("Empty queue\n");
        return;
    }
    q->front++;
}

int isEmpty(struct Queue *q)
{
    return q->rear < q->front; // Returns 1 if empty, otherwise 0
}

void dfs(int **adjMat, int n, int node, int *visited)
{
    visited[node] = 1;       // Mark the current node as visited
    printf("%d ", node + 1); // Print the node (adding 1 for 1-based indexing)

    // Visit all adjacent nodes
    for (int i = 0; i < n; i++)
    {
        if (adjMat[node][i] == 1 && !visited[i]) // Check for unvisited neighbors
        {
            dfs(adjMat, n, i, visited); // Recursively visit the neighbor
        }
    }
}

void bfs(int **adjMat, int n, int start)
{
    struct Queue *q = initialiseQueue(n);
    int *visited = (int *)malloc(n * sizeof(int));

    // Initialize the visited array
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0; // Mark all nodes as unvisited
    }

    // Start from the given node
    visited[start] = 1; // Mark the start node as visited
    push(q, start);

    printf("BFS Traversal: ");

    while (!isEmpty(q))
    {
        int node = top(q);
        printf("%d ", node + 1); // Print the node (adding 1 for 1-based indexing)
        pop(q);

        // Visit all adjacent nodes
        for (int i = 0; i < n; i++)
        {
            if (adjMat[node][i] == 1 && !visited[i]) // Check for unvisited neighbors
            {
                visited[i] = 1; // Mark as visited
                push(q, i);     // Add to the queue
            }
        }
    }

    printf("\n");
    free(q->arr);
    free(q);
    free(visited);
}

int main()
{
    int n;
    printf("Enter the total number of nodes\n");
    scanf("%d", &n);

    // Allocate memory for adjacency matrix
    int **adjMat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        adjMat[i] = (int *)malloc(n * sizeof(int)); // Allocate row-wise
    }

    // Initialize the adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjMat[i][j] = 0;
        }
    }

    // Input the edges
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
            adjMat[u - 1][v - 1] = 1; // Mark the edge in the adjacency matrix
        }
    }

    // Initialize visited array for DFS
    int *visited = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0; // Mark all nodes as unvisited
    }

    // Choose the search algorithm
    int choice;
    printf("Choose the search algorithm:\n1. DFS\n2. BFS\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("DFS Traversal: ");
        dfs(adjMat, n, 0, visited); // Start DFS from node 0
        printf("\n");
        break;
    case 2:
        bfs(adjMat, n, 0); // Start BFS from node 0
        break;
    default:
        printf("Invalid choice\n");
        break;
    }

    // Free memory
    free(visited);
    for (int i = 0; i < n; i++)
    {
        free(adjMat[i]);
    }
    free(adjMat);

    return 0;
}
