#include "my_strcasecmp.h"

int endcase(const char *s1, const char *s2, unsigned index)
{
    if (s1[index] == '\0' && s2[index] == '\0')
        return 0;

    if (s1[index] == '\0')
        return -1;

    return 1;
}

int my_strcasecmp(const char *s1, const char *s2)
{
    unsigned index = 0;
    for (; s1[index] != '\0' && s2[index] != '\0'; index++)
    {
        if ('A' <= s1[index] && s1[index] <= 'Z')
        {
            if ('A' <= s2[index] && s2[index] <= 'Z')
            {
                if (s1[index] < s2[index])
                    return -1;

                if (s1[index] > s2[index])
                    return 1;
            }
            else if ('a' <= s2[index] && s2[index] <= 'z')
            {
                if (s1[index] < (s2[index] - 32))
                    return -1;

                if (s1[index] > (s2[index] - 32))
                    return 1;
            }
        }

        else if ('a' <= s1[index] && s1[index] <= 'z')
        {
            if ('a' <= s2[index] && s2[index] <= 'z')
            {
                if (s1[index] < s2[index])
                    return -1;

                if (s1[index] > s2[index])
                    return 1;
            }
            else if ('A' <= s2[index] && s2[index] <= 'Z')
            {
                if (s1[index] < (s2[index] + 32))
                    return -1;

                if (s1[index] > (s2[index] + 32))
                    return 1;
            }
        }
        else
        {
            if (s1[index] < s2[index])
                return -1;

            if (s1[index] > s2[index])
                return 1;
        }
    }

    return endcase(s1, s2, index);
}
