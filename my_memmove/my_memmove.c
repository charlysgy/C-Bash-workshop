#include "my_memmove.h"

void *my_memmove(void *dest, const void *src, size_t n)
{
    char *dst = dest;
    const char *sr = src;
    if (src < dest)
    {
        for (size_t i = n; i > 0; i--)
        {
            *(dst + i - 1) = *(sr + i - 1);
        }
    }
    else
    {
        for (size_t i = 0; i < n; i++)
        {
            *(dst + i) = *(sr + i);
        }
    }

    return dest;
}
