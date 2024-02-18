#include "int_vector_vice_max.h"

int int_vector_vice_max(const struct int_vector vec)
{
    int max = vec.data[0];
    int vmax = vec.data[0];

    for (unsigned index = 0; index < vec.size; index++)
    {
        max = max < vec.data[index] ? vec.data[index] : max;
        if (vmax == max && vec.data[index] < max)
        {
            vmax = vec.data[index];
        }
        else
            vmax = vmax < vec.data[index] && vec.data[index] < max
                ? vec.data[index]
                : vmax;
    }

    return vmax;
}
