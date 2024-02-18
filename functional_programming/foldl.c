#include "functional_programming.h"

int foldl(int *array, size_t len, int (*func)(int, int))
{
    if (len > 0)
        return func(foldl(array, len - 1, func), array[len - 1]);
    return 0;
}
