#include "simple_fnmatch.h"

#include <fnmatch.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int simple_fnmatch(const char *pattern, const char *string)
{
    if (*pattern == '\0' && *string == '\0')
    {
        return 0;
    }
    if (*pattern == '*' && *string == '\0')
    {
        return simple_fnmatch(pattern + 1, string);
    }
    if (*pattern == '\0' || *string == '\0')
    {
        return FNM_NOMATCH;
    }
    if (*pattern == '*')
    {
        int a = 0;
        int b = 0;
        while (*(pattern + a) == '*')
            a++;
        while (string[b] != '\0')
        {
            if (simple_fnmatch(pattern + a, string + b++) == 0)
                return 0;
        }
        if (simple_fnmatch(pattern + a, string + b) == 0)
            return 0;
        return simple_fnmatch(pattern + a, string);
    }
    if (*pattern == '?')
        return simple_fnmatch(pattern + 1, string + 1);
    if (*pattern == '\\')
    {
        if (*(pattern + 1) == *string)
            return simple_fnmatch(pattern + 2, string + 1);
        else
            return FNM_NOMATCH;
    }
    if (*pattern == *string)
        return simple_fnmatch(pattern + 1, string + 1);
    return FNM_NOMATCH;
}
