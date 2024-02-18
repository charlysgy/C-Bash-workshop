#include "int_vector_print.h"

#include <stdio.h>

void int_vector_print(const struct int_vector vec)
{
    unsigned index = 0;
    for (; index < vec.size - 1; index++)
    {
        printf("%d ", vec.data[index]);
    }

    printf("%d\n", vec.data[index]);
}
