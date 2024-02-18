#include <stdio.h>

unsigned str_len(const char *s)
{
    unsigned i = 0;
    for (; s[i] != '\0'; i++)
        continue;

    return i;
}

int find_max(int histo[], int size)
{
    int max_index = 0;
    for (int i = 0; i < size; i++)
    {
        if (histo[i] > histo[max_index])
            max_index = i;
    }

    return max_index;
}

void build_histo(int histo[], const char *text)
{
    for (unsigned i = 0; text[i] != '\0'; i++)
        histo[text[i] - 'A']++;
}

void build_max_order(int histo[], int max_order[], int size)
{
    int order = 1;
    for (int i = 0; i < size; i++)
    {
        int max_index = find_max(histo, size);
        if (histo[max_index] > 0)
        {
            histo[max_index] = -1;
            max_order[max_index] = order;
        }
        order++;
    }
}

void freq_analysis(const char text[], const char table[])
{
    int histo[26] = { 0 };
    int max_order[26] = { 0 };
    build_histo(histo, text);
    build_max_order(histo, max_order, 26);

    for (unsigned i = 0; i < 26; i++)
    {
        if (max_order[i] > 0)
            printf("%c %c\n", 'A' + i, table[max_order[i] - 1]);
    }
}
