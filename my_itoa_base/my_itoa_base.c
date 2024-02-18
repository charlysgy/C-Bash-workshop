#include "my_itoa_base.h"

void reverse(char *s, unsigned len)
{
    unsigned start = 0;
    unsigned end = len - 1;

    while (start < end)
    {
        char tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
        end--;
        start++;
    }
}

int str_len(const char *s)
{
    int len = 0;
    for (; s[len] != '\0'; len++)
        continue;
    return len;
}

char *my_itoa_base(int n, char *s, const char *base)
{
    int baselen = str_len(base);
    if (baselen <= 1)
        return s;

    if (n == 0)
    {
        s[0] = base[0];
        s[1] = '\0';
        return s;
    }

    unsigned index = 0;
    int coef = 1;
    if (n < 0 && baselen == 10)
    {
        coef = -1;
        n = -n;
    }

    while (n > 0)
    {
        int tmp = n % baselen;
        s[index] = base[tmp];
        index++;
        n /= baselen;
    }

    if (coef == -1)
        s[index++] = '-';

    s[index] = '\0';
    reverse(s, index);
    return s;
}
