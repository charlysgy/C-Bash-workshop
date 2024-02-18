#include "my_strlowcase.h"

void my_strlowcase(char *s)
{
    for (unsigned index = 0; s[index] != '\0'; index++)
    {
        if ('A' <= s[index] && s[index] <= 'Z')
        {
            s[index] = s[index] + ('a' - 'A');
        }
    }
}
