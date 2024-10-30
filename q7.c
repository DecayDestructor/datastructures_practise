// Write a program to implement Queue using a circular array

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Queue
{
    int front, rear;
    int size;
    int *arr;
};

// Function to create a queue with given size

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
}

// Function to dequeue an item

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->arr[queue->front];
    if (queue->front == queue->rear)
    {
        printf("Queue is full\n");
        queue->front = queue->rear = -1;
    }
    else
        queue->front = (queue->front + 1) % queue->size;
    return item;
}
