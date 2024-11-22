#include <stdlib.h>
#include <stdio.h>

typedef struct Heap
{
    int *arr;
    int size;
    int capacity;
} Heap;

void maxHeapify(Heap *, int);

Heap *createHeap(int *arr, int capacity)
{
    Heap *hp = (Heap *)malloc(sizeof(Heap));
    hp->arr = (int *)malloc(capacity * sizeof(int));
    hp->capacity = capacity;
    hp->size = 0;
    int i;
    for (i = 0; i < capacity; i++)
    {
        hp->arr[i] = arr[i];
    }
    hp->size = i;
    i = (hp->size - 2) / 2;
    while (i >= 0)
    {
        maxHeapify(hp, i);
        i--;
    }
    return hp;
}

int extractMax(Heap *hp)
{
    if (hp->size == 1)
    {
        return -1;
    }
    int maxi = hp->arr[0];
    hp->arr[0] = hp->arr[hp->size - 1];
    hp->size--;
    maxHeapify(hp, 0);
    return maxi;
}

void heapSort(Heap *hp)
{
    int originalSize = hp->size;
    printf("%d\n", hp->size);
    // hp->size--;
    while (hp->size > 1)
    {
        int temp = hp->arr[0];
        hp->arr[0] = hp->arr[hp->size - 1];
        hp->arr[hp->size - 1] = temp;
        hp->size--;
        maxHeapify(hp, 0);
    }
    hp->size = originalSize;
}

void maxHeapify(Heap *hp, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int maxi = i;

    if (left <= 0 || left >= hp->size)
    {
        left = -1;
    }
    if (right <= 0 || right >= hp->size)
    {
        right = -1;
    }
    if (left != -1 && hp->arr[left] >= hp->arr[maxi])
        maxi = left;
    if (right != -1 && hp->arr[right] >= hp->arr[maxi])
        maxi = right;

    if (maxi != i)
    {
        int temp = hp->arr[i];
        hp->arr[i] = hp->arr[maxi];
        hp->arr[maxi] = temp;
        maxHeapify(hp, maxi);
    }
}
int main()
{
    // Input array
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int capacity = sizeof(arr) / sizeof(arr[0]);

    // Create the heap
    Heap *hp = createHeap(arr, capacity);

    printf("Heap created:\n");
    for (int i = 0; i < hp->size; i++)
    {
        printf("%d ", hp->arr[i]);
    }
    printf("\n");

    // Extract the maximum element
    int maxElement = extractMax(hp);
    printf("Extracted max element: %d\n", maxElement);

    printf("Heap after extracting max:\n");
    for (int i = 0; i < hp->size; i++)
    {
        printf("%d ", hp->arr[i]);
    }
    printf("\n");

    // Perform heap sort
    printf("%d\n", hp->size);
    heapSort(hp);

    printf("Array after heap sort:\n");
    for (int i = 0; i < hp->size; i++)
    {
        printf("%d ", hp->arr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(hp->arr);
    free(hp);

    return 0;
}