#include "array_max_min.h"

void array_max_min(int tab[], size_t len, int *max, int *min)
{
    if (!tab || len == 0)
        return;

    *max = tab[0];
    *min = tab[0];

    for (size_t index = 0; index < len; index++)
    {
        *max = *max < tab[index] ? tab[index] : *max;
        *min = *min > tab[index] ? tab[index] : *min;
    }
}
