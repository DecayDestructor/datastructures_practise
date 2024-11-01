// Write a program to maintain multiple queues in a single array.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100

struct Queue
{
    int front;
    int rear;
    int arr[SIZE];
};

struct mega_queue
{
    struct Queue **queues;
};

// Function to initialize the mega queue

struct mega_queue *initialize_mega_queue()
{
    struct mega_queue *mq = (struct mega_queue *)malloc(sizeof(struct mega_queue));
    mq->queues = (struct Queue **)malloc(SIZE * sizeof(struct Queue));
    for (int i = 0; i < SIZE; i++)
    {
        mq->queues[i] = (struct Queue *)malloc(sizeof(struct Queue));
        mq->queues[i]->front = 0;
        mq->queues[i]->rear = -1;
    }
    return mq;
}

// Function to add an element to a specific queue

void add_to_queue(struct mega_queue *mq, int queue_number, int item)
{
    struct Queue *q = mq->queues[queue_number];
    if (q->rear == SIZE - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    else
    {
        q->arr[++q->rear] = item;
        // show the pushed element
        printf("Pushed %d to queue %d\n", item, queue_number);
    }
}

// Function to remove an element from a specific queue

int remove_from_queue(struct mega_queue *mq, int queue_number)
{
    if (mq->queues[queue_number]->front > mq->queues[queue_number]->rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        return mq->queues[queue_number]->arr[mq->queues[queue_number]->front++];
    }
}

// Function to display all elements in a specific queue

void display_queue(struct mega_queue *mq, int queue_number)
{
    if (mq->queues[queue_number]->front > mq->queues[queue_number]->rear)
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = mq->queues[queue_number]->front; i <= mq->queues[queue_number]->rear; i++)
    {
        printf("%d ", mq->queues[queue_number]->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct mega_queue *mq = initialize_mega_queue();
    add_to_queue(mq, 0, 10);
    add_to_queue(mq, 0, 20);
    add_to_queue(mq, 1, 30);
    add_to_queue(mq, 1, 40);
    display_queue(mq, 0);
    display_queue(mq, 1);
    return 0;
}
