#include "my_memset.h"

void *my_memset(void *s, int c, size_t n)
{
    char *ptr = s;
    for (size_t i = 0; i < n; i++)
    {
        *(ptr + i) = c;
    }

    return ptr;
}
