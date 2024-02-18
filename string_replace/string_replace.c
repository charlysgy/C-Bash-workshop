#include "string_replace.h"

#include <stdio.h>
unsigned str_len(const char *str)
{
    unsigned len = 0;
    while (str[len++] != '\0')
        ;

    return len;
}

char *string_replace(char c, const char *str, const char *pattern)
{
    if (!str)
        return NULL;

    unsigned len_str = str_len(str);
    int pattern_len = -1;

    if (pattern && pattern[0] != '\0')
        pattern_len = str_len(pattern);

    unsigned new_len = len_str;

    for (unsigned index = 0; str[index] != '\0'; index++)
    {
        if (str[index] == c)
            new_len += pattern_len;
    }
    printf("%d, %d, %d\n", len_str, new_len, pattern_len);
    char *res = calloc(sizeof(char), new_len);

    unsigned offset = 0;
    for (unsigned index = 0; str[index] != '\0'; index++)
    {
        if (str[index] == c)
        {
            if (pattern_len != -1)
            {
                for (unsigned i = 0; pattern[i] != '\0'; i++)
                {
                    res[index + offset + i] = pattern[i];
                }
            }
            offset += pattern_len;
        }
        else
            res[index + offset] = str[index];
    }

    return res;
}
int main(int argc, char **argv)
{
    char *res = string_replace(argv[1][0], argv[2], argv[argc - 1]);
    printf("%s => %s\n", argv[2], res);

    free(res);

    return 0;
}
