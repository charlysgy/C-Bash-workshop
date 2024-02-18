#include "my_itoa.h"

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

char *my_itoa(int value, char *s)
{
    if (value == 0)
    {
        s[0] = '0';
        s[1] = '\0';
        return s;
    }

    unsigned index = 0;
    int coef = 1;
    if (value < 0)
    {
        coef = -1;
        value = -value;
    }

    while (value > 0)
    {
        int tmp = value % 10;
        s[index] = tmp + '0';
        index++;
        value /= 10;
    }

    if (coef == -1)
        s[index++] = '-';

    s[index] = '\0';
    reverse(s, index);
    return s;
}
