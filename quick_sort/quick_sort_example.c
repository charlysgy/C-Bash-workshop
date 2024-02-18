#include <stdio.h>

#define LEN 15

void print_tab(int *tab)
{
    int i = 0;
    for (; i < LEN - 1; ++i)
        printf("%d ", tab[i]);
    printf("%d\n", tab[i]);
}

void swap(int *tab, int a, int b)
{
    int tmp = tab[a];
    tab[a] = tab[b];
    tab[b] = tmp;
}

void partition(int *tab, int beg, int end)
{
    if (beg >= end)
        return;

    int pivot = tab[end];
    int j = beg - 1;

    for (int i = beg; i <= end; i++)
    {
        if (tab[i] <= pivot)
        {
            j++;
            swap(tab, i, j);
        }
    }

    print_tab(tab);
    printf("%d, %d\n", beg, j - 1);
    printf("%d, %d\n", j, end);
    partition(tab, beg, j - 1);
    partition(tab, j, end);
}

void quicksort(int *tab, int len)
{
    if (!tab || len == 1)
        return;

    printf("%d, %d\n", 0, len - 1);
    partition(tab, 0, len - 1);
}

int main(void)
{
    unsigned i = 0;
    int tab[] = { 10, 11, 2, 3, 8, 5, 7, 6, 26, 30, 2, 1, 17, 13, 14 };

    unsigned size = sizeof(tab) / sizeof(int);

    quicksort(tab, size);

    for (; i < size - 1; ++i)
        printf("%d ", tab[i]);
    printf("%d\n", tab[i]);

    return 0;
}
