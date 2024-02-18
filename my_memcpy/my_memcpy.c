#include "my_memcpy.h"

void *my_memcpy(void *dest, const void *source, size_t num)
{
    const char *src = source;
    char *dst = dest;
    for (size_t i = 0; i < num; i++)
    {
        *(dst + i) = *(src + i);
    }

    return dst;
}
