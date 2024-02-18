#include "null_terminated_arrays.h"

#include <stddef.h>

void reverse_matrix(const char ***matrix)
{
    size_t start = 0;
    size_t end = 0;
    for (; matrix[end] != NULL; end++)
        continue;

    end--;
    for (; start < end; start++, end--)
    {
        const char **tmp = matrix[start];
        matrix[start] = matrix[end];
        matrix[end] = tmp;
    }

    for (end = 0; matrix[end] != NULL; end++)
        continue;

    end--;
    size_t in_start = 0;
    size_t in_end = 0;

    for (size_t index = 0; index <= end; index++)
    {
        in_start = 0;
        in_end = 0;
        for (; matrix[index][in_end] != NULL; in_end++)
            continue;
        in_end = in_end == 0 ? in_end : in_end - 1;
        for (; in_start < in_end; in_start++, in_end--)
        {
            const char *tmp = matrix[index][in_start];
            matrix[index][in_start] = matrix[index][in_end];
            matrix[index][in_end] = tmp;
        }
    }
}
