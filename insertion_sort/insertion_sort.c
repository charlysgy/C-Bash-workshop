#include "insertion_sort.h"

#include <stdlib.h>

void swap(void **arr, size_t i, size_t j)
{
    void *tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void insertion_sort(void **array, f_cmp comp)
{
    for (size_t i = 0; array[i] != NULL; i++)
    {
        for (size_t j = 0; array[j] != NULL; j++)
        {
            if (comp(array[i], array[j]) < 0)
                swap(array, i, j);
        }
    }
}
