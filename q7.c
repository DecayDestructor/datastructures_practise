#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Queue
{
    int front, rear;
    int size;
    int *arr;
};

// Function to create a queue with a given size
struct Queue *createQueue(int size)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    if (!queue)
    {
        printf("Memory error\n");
        return NULL;
    }
    queue->arr = (int *)malloc(size * sizeof(int));
    if (!queue->arr)
    {
        printf("Memory error\n");
        free(queue);
        return NULL;
    }
    queue->front = queue->rear = -1;
    queue->size = size;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue *queue)
{
    return ((queue->rear + 1) % queue->size == queue->front);
}

// Function to enqueue an item
void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
    {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->rear = (queue->rear + 1) % queue->size;
    queue->arr[queue->rear] = item;
    printf("Enqueued: %d\n", item);
}

// Function to dequeue an item
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    // printf("%d %d", queue->front, queue->rear);
    int item = queue->arr[queue->front];
    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % queue->size;
    }
    printf("Dequeued: %d\n", item);
    return item;
}

// Function to display the queue
void display(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i = queue->front;
    while (1)
    {
        printf("%d ", queue->arr[i]);
        if (i == queue->rear)
            break;
        i = (i + 1) % queue->size;
    }
    printf("\n");
}

// Main function to test the queue
int main()
{
    struct Queue *queue = createQueue(MAX_SIZE);

    enqueue(queue, 10);
    dequeue(queue);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    display(queue);

    dequeue(queue);
    dequeue(queue);

    display(queue);

    enqueue(queue, 60);
    enqueue(queue, 70);

    display(queue);

    return 0;
}
