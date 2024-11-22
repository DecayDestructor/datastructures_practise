#include <malloc.h>
#include <stdio.h>

// Declare a heap structure
struct Heap
{
    int *arr;
    int size;
    int capacity;
};

// define the struct Heap name
typedef struct Heap heap;

// forward declarations
heap *createHeap(int capacity, int *nums);
void insertHelper(heap *h, int index);
void minHeapify(heap *h, int index);
int extractMin(heap *h);
void insert(heap *h, int data);
void heapSort(heap *h);
void printHeap(heap *h);

// Define a createHeap function
heap *createHeap(int capacity, int *nums)
{
    heap *h = (heap *)malloc(sizeof(heap));

    if (h == NULL)
    {
        printf("Memory error");
        return NULL;
    }

    h->size = 0;
    h->capacity = capacity;

    h->arr = (int *)malloc(capacity * sizeof(int));
    if (h->arr == NULL)
    {
        printf("Memory error");
        return NULL;
    }

    int i;
    for (i = 0; i < capacity; i++)
    {
        h->arr[i] = nums[i];
    }

    h->size = i;
    i = (h->size - 2) / 2;
    while (i >= 0)
    {
        minHeapify(h, i);
        i--;
    }
    return h;
}

void insertHelper(heap *h, int index)
{
    int parent = (index - 1) / 2;

    if (h->arr[parent] > h->arr[index])
    {
        int temp = h->arr[parent];
        h->arr[parent] = h->arr[index];
        h->arr[index] = temp;

        insertHelper(h, parent);
    }
}

void minHeapify(heap *h, int index)
{
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int min = index;

    if (left >= h->size || left < 0)
        left = -1;
    if (right >= h->size || right < 0)
        right = -1;

    if (left != -1 && h->arr[left] < h->arr[min])
        min = left;
    if (right != -1 && h->arr[right] < h->arr[min])
        min = right;

    if (min != index)
    {
        int temp = h->arr[min];
        h->arr[min] = h->arr[index];
        h->arr[index] = temp;

        minHeapify(h, min);
    }
}

int extractMin(heap *h)
{
    int deleteItem;

    if (h->size == 0)
    {
        printf("\nHeap is empty.");
        return -999;
    }

    deleteItem = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    minHeapify(h, 0);
    return deleteItem;
}

void insert(heap *h, int data)
{
    if (h->size < h->capacity)
    {
        h->arr[h->size] = data;
        insertHelper(h, h->size);
        h->size++;
    }
}

// Heap sort function for Min-Heap
void heapSort(heap *h)
{
    int originalSize = h->size;

    while (h->size > 1)
    {
        // Swap the root (min element) with the last element
        int temp = h->arr[0];
        h->arr[0] = h->arr[h->size - 1];
        h->arr[h->size - 1] = temp;

        // Reduce the size of the heap
        h->size--;

        // Heapify the root
        minHeapify(h, 0);
    }

    // Restore the original heap size
    h->size = originalSize;

    // The array is now sorted in descending order.
    // Reverse the array to get ascending order if needed.
    for (int i = 0; i < h->size / 2; i++)
    {
        int temp = h->arr[i];
        h->arr[i] = h->arr[h->size - 1 - i];
        h->arr[h->size - 1 - i] = temp;
    }
}

void printHeap(heap *h)
{
    for (int i = 0; i < h->size; i++)
    {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

void main()
{
    int arr[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    heap *hp = createHeap(9, arr);

    printf("Original Min-Heap:\n");
    printHeap(hp);

    printf("\nHeap after extracting min:\n");
    extractMin(hp);
    printHeap(hp);

    printf("\nHeap after sorting:\n");
    heapSort(hp);
    printHeap(hp);
}
