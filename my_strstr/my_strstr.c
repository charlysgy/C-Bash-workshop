#include "my_strstr.h"

int my_strstr(const char *haystack, const char *needle)
{
    if (needle[0] == '\0')
        return 0;

    int i = 0;
    for (; haystack[i] != '\0'; i++)
    {
        int j = 0;
        for (; needle[j] != '\0' && haystack[i + j] != '\0'; j++)
        {
            if (haystack[i + j] != needle[j])
                break;
        }
        if (needle[j] == '\0')
            return i;
    }

    return -1;
}
