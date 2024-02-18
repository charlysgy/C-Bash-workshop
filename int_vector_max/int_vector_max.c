#include "int_vector_max.h"

int int_vector_max(const struct int_vector vec)
{
    int max = vec.data[0];

    for (unsigned i = 0; i < vec.size; i++)
    {
        max = max < vec.data[i] ? vec.data[i] : max;
    }

    return max;
}
