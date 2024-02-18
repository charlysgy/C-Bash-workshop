#include "levenshtein.h"

#include <stdlib.h>

size_t str_len(const char *s)
{
    size_t len = 0;
    for (; s[len] != '\0'; len++)
        continue;

    return len;
}

size_t levenshtein(const char *s1, const char *s2)
{
    size_t len1 = str_len(s1);
    size_t len2 = str_len(s2);

    int **mat = malloc(sizeof(int *) * (len1 + 1));
    for (size_t i = 0; i <= len1; i++)
    {
        mat[i] = malloc(sizeof(int) * (len2 + 1));
        for (size_t j = 0; j <= len2; j++)
            mat[i][j] = 0;
    }

    for (size_t i = 0; i <= len1; i++)
        mat[i][0] = i;

    for (size_t j = 0; j <= len2; j++)
        mat[0][j] = j;

    for (size_t i = 1; i <= len1; i++)
    {
        for (size_t j = 1; j <= len2; j++)
        {
            int sub = 0;
            if (s1[i - 1] != s2[j - 1])
                sub = 1;
            int min = mat[i - 1][j] + 1;
            min = mat[i][j - 1] + 1 < min ? mat[i][j - 1] + 1 : min;
            min = mat[i - 1][j - 1] + sub < min ? mat[i - 1][j - 1] + sub : min;
            mat[i][j] = min;
        }
    }

    size_t tmp = mat[len1][len2];

    for (size_t i = 0; i <= len1; i++)
    {
        free(mat[i]);
    }
    free(mat);

    return tmp;
}
