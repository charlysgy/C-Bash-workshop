#include "element_count.h"

size_t element_count(int *begin, int *end)
{
    size_t count = 0;

    while (begin < end)
    {
        if (*begin)
            count++;

        begin = begin + 1;
    }

    return count;
}
