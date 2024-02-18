#include "my_strtok_r.h"

#include <stddef.h>

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    if (!*saveptr)
        *saveptr = str;
    else if (!str)
        str = *saveptr;
    else if (**saveptr == '\0')
        *saveptr = str;
    if (*str == '\0')
        return NULL;

    unsigned i = 0;
    for (; (*saveptr)[i] != '\0'; i++)
    {
        for (unsigned j = 0; delim[j] != '\0'; j++)
        {
            if ((*saveptr)[i] == delim[j])
            {
                if (*str == delim[j])
                {
                    str += 1;
                }
                else
                {
                    *((*saveptr) + i) = '\0';
                    *saveptr = (*saveptr) + i + 1;
                    return str;
                }
            }
        }
    }

    if ((*saveptr)[i] == '\0')
        *saveptr = (*saveptr) + i;

    if (*saveptr == str)
        return NULL;
    return str;
}
