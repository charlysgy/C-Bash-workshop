#include "int_vector_hill.h"

#include <stddef.h>

int int_vector_hill(struct int_vector vec)
{
    if (vec.size == 0)
        return -1;

    for (unsigned i = 0; i < vec.size; i++)
    {
        if (vec.data[i] < 0)
            return -1;
    }

    size_t hill = 0;
    size_t index = 0;

    while (index < vec.size - 1)
    {
        if (vec.data[index] < 0)
            return -1;

        else if (vec.data[index] == vec.data[index + 1])
            index++;

        else if (vec.data[index] > vec.data[index + 1])
            break;

        else
            hill = ++index;
    }

    while (index < vec.size - 1 && vec.data[index] == vec.data[index + 1])
        index++;

    while (index < vec.size - 1)
    {
        if (vec.data[index] < 0 || vec.data[index] < vec.data[index + 1])
            return -1;
        index++;
    }

    return hill;
}
