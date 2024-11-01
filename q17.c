#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the adjacency list
struct Node
{
    int vertex;
    struct Node *next;
};

// Structure for the adjacency list
struct Graph
{
    int numVertices;
    struct Node **adjLists; // Array of adjacency lists
};

// Function to create a new adjacency list node
struct Node *createNode(int vertex)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with n vertices
struct Graph *createGraph(int n)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = n;
    graph->adjLists = (struct Node **)malloc(n * sizeof(struct Node *));

    // Initialize each adjacency list
    for (int i = 0; i < n; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph (undirected)
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add an edge from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add an edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS function
void dfs(struct Graph *graph, int vertex, int *visited)
{
    visited[vertex] = 1;       // Mark the current vertex as visited
    printf("%d ", vertex + 1); // Print the vertex (1-based index)

    // Visit all the adjacent vertices
    struct Node *temp = graph->adjLists[vertex];
    while (temp)
    {
        if (!visited[temp->vertex])
        {
            dfs(graph, temp->vertex, visited); // Recursive call
        }
        temp = temp->next;
    }
}

// BFS function
void bfs(struct Graph *graph, int start)
{
    int *visited = (int *)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++)
    {
        visited[i] = 0; // Mark all vertices as unvisited
    }

    struct Queue
    {
        int front;
        int rear;
        int *arr;
        int size;
    };

    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = graph->numVertices;
    queue->arr = (int *)malloc(queue->size * sizeof(int));

    visited[start] = 1;                // Mark the start vertex as visited
    queue->arr[++queue->rear] = start; // Enqueue the start vertex

    printf("BFS Traversal: ");
    while (queue->front <= queue->rear)
    {
        int currentVertex = queue->arr[queue->front++];
        printf("%d ", currentVertex + 1); // Print the vertex (1-based index)

        // Visit all adjacent vertices
        struct Node *temp = graph->adjLists[currentVertex];
        while (temp)
        {
            if (!visited[temp->vertex])
            {
                visited[temp->vertex] = 1;                // Mark as visited
                queue->arr[++queue->rear] = temp->vertex; // Enqueue
            }
            temp = temp->next;
        }
    }

    printf("\n");
    free(queue->arr);
    free(queue);
    free(visited);
}

int main()
{
    int n;
    printf("Enter the total number of nodes\n");
    scanf("%d", &n);

    struct Graph *graph = createGraph(n);

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
            addEdge(graph, u - 1, v - 1); // Adjust for 0-based indexing
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
        dfs(graph, 0, visited); // Start DFS from node 0
        printf("\n");
        break;
    case 2:
        bfs(graph, 0); // Start BFS from node 0
        break;
    default:
        printf("Invalid choice\n");
        break;
    }

    // Free memory
    free(visited);
    for (int i = 0; i < n; i++)
    {
        struct Node *temp = graph->adjLists[i];
        while (temp)
        {
            struct Node *toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);

    return 0;
}
