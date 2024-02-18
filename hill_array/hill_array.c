#include "hill_array.h"

#include <stddef.h>

int top_of_the_hill(int tab[], size_t len)
{
    if (len == 0)
        return -1;

    size_t hill = 0;
    size_t index = 0;

    while (index < len - 1)
    {
        if (tab[index] < 0)
            return -1;

        else if (tab[index] == tab[index + 1])
            index++;

        else if (tab[index] > tab[index + 1])
            break;

        else
            hill = ++index;
    }

    while (index < len - 1 && tab[index] == tab[index + 1])
        index++;

    while (index < len - 1)
    {
        if (tab[index] < 0 || tab[index] < tab[index + 1])
            return -1;
        index++;
    }

    return hill;
}
