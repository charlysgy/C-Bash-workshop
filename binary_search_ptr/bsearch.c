#include "bsearch.h"

int *binary_search(int *begin, int *end, int elt)
{
    if (begin == end)
        return begin;

    end--;
    while (begin < end)
    {
        int *pivot = begin + (end - begin) / 2;

        if (*pivot == elt)
            return pivot;

        if (elt < *pivot)
            end = pivot - 1;

        else
            begin = pivot + 1;
    }

    if (*begin < elt)
        return begin + 1;

    return begin;
}
