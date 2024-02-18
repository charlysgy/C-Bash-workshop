#include <assert.h>
#include <stdlib.h>

#include "heap.h"

void swap(int *array, int i, int j)
{
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

size_t get_max_parentchild_index(struct heap *heap, size_t index)
{
    if (2 * index + 1 <= heap->size)
    {
        size_t element = heap->array[index - 1];
        size_t leftchild = heap->array[2 * index - 1];
        size_t rightchild = heap->array[2 * index];

        size_t max_index = leftchild < rightchild ? 2 * index + 1 : 2 * index;
        size_t max_element = heap->array[max_index - 1];
        max_index = element < max_element ? max_index : 0;

        return max_index;
    }
    else if (2 * index <= heap->size)
    {
        size_t element = heap->array[index - 1];
        size_t leftchild = heap->array[2 * index - 1];

        return element < leftchild ? 2 * index : 0;
    }
    return 0;
}

void heapify(struct heap *heap, size_t index)
{
    size_t max_index = get_max_parentchild_index(heap, index);

    if (max_index == 0)
        return;

    swap(heap->array, index - 1, max_index - 1);
    heapify(heap, max_index);
}

int pop(struct heap *heap)
{
    assert(heap->size != 0);

    int to_return = heap->array[0];

    swap(heap->array, 0, heap->size - 1);

    heap->size--;
    heapify(heap, 1);

    if (heap->capacity > 8 && heap->size < heap->capacity / 2)
    {
        heap->capacity /= 2;
        heap->array = realloc(heap->array, heap->capacity * sizeof(int));
    }

    return to_return;
}
