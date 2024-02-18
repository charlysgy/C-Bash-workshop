#include "my_strspn.h"

size_t my_strspn(const char *s, const char *accept)
{
    size_t len = 0;

    for (unsigned i = 0; s[i] != '\0'; i++, len++)
    {
        int is_valid = 0;
        for (unsigned j = 0; accept[j] != '\0'; j++)
        {
            if (s[i] == accept[j])
            {
                is_valid = 1;
                break;
            }
        }
        if (is_valid == 0)
            return len;
    }
    return len;
}
