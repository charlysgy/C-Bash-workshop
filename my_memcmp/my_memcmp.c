#include "my_memcmp.h"

int my_memcmp(const void *s1, const void *s2, size_t num)
{
    const char *arr1 = s1;
    const char *arr2 = s2;
    for (size_t i = 0; i < num; i++)
    {
        int diff = *(arr1 + i) - *(arr2 + i);
        if (diff)
            return diff;
    }
    return 0;
}
