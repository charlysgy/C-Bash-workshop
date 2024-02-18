#include <stdio.h>

#include "heap.h"

static void print_heap_rec(const struct heap *heap, size_t index)
{
    if (index > heap->size)
        return;

    if (index == 1)
        printf("%d", heap->array[index - 1]);
    else
        printf(" %d", heap->array[index - 1]);
    print_heap_rec(heap, 2 * index);
    print_heap_rec(heap, 2 * index + 1);
}

void print_heap(const struct heap *heap)
{
    if (heap->size == 0)
        return;

    print_heap_rec(heap, 1);
    printf("\n");
}
