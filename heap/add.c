#include <stdlib.h>

#include "heap.h"

void add(struct heap *heap, int val)
{
    if (heap->size == heap->capacity)
    {
        heap->capacity *= 2;
        heap->array = realloc(heap->array, heap->capacity * sizeof(int));
        if (!heap->array)
            return;
    }

    heap->array[heap->size] = val;
    heap->size++;

    int index = heap->size - 1;
    while (index > 0 && heap->array[index / 2] < val)
    {
        int tmp = heap->array[index];
        heap->array[index] = heap->array[index / 2];
        heap->array[index / 2] = tmp;
        index /= 2;
    }
}
