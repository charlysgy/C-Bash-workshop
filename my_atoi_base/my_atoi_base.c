#include "my_atoi_base.h"

unsigned str_len(const char *s)
{
    unsigned len = 0;
    for (; s[len] != '\0'; len++)
        continue;

    return len;
}

int my_atoi_base(const char *str, const char *base)
{
    unsigned base_len = str_len(base);
    int res = 0;
    int index = 0;
    int coef = 1;

    while (str[index] == ' ')
    {
        if (str[index] == '\0')
            return 0;
        index++;
    }

    if (str[index] == '-')
    {
        coef = -1;
        index++;
    }
    else if (str[index] == '+')
    {
        index++;
    }
    else if (str[index] == '\0')
    {
        return 0;
    }

    while (str[index] != '\0')
    {
        int base_index = -1;
        for (unsigned i = 0; i < base_len; i++)
        {
            if (str[index] == base[i])
            {
                base_index = i;
                break;
            }
        }

        if (base_index == -1)
            return 0;

        res *= base_len;
        res += base_index;
        index++;
    }
    return res * coef;
}
