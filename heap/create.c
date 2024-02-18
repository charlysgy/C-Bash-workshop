#include <stdlib.h>

#include "heap.h"

struct heap *create_heap(void)
{
    struct heap *res = calloc(sizeof(struct heap), 1);
    if (!res)
        return NULL;

    res->array = calloc(sizeof(int), 8);
    if (!res->array)
        return NULL;

    res->size = 0;
    res->capacity = 8;

    return res;
}
