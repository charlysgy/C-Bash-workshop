#include "int_vector_insert_sort.h"

static struct int_vector swap(struct int_vector vec, size_t i, size_t j)
{
    int tmp = vec.data[i];
    vec.data[i] = vec.data[j];
    vec.data[j] = tmp;

    return vec;
}

struct int_vector int_vector_insert_sort(struct int_vector vec)
{
    for (unsigned i = 0; i < vec.size; i++)
    {
        for (unsigned j = i; j > 0; j--)
        {
            if (vec.data[j - 1] > vec.data[j])
                vec = swap(vec, j, j - 1);
        }
    }

    return vec;
}
