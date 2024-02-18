#include "heap_sort.h"

void swap(int *array, size_t i, size_t j)
{
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

void heapify(int *array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (array[j] > array[i])
                swap(array, i, j);
        }
    }
}

void heap_sort(int *array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (array[j] < array[i])
                swap(array, i, j);
        }
    }
}
