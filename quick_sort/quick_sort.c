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

    partition(tab, beg, j - 1);
    partition(tab, j, end);
}

void quicksort(int *tab, int len)
{
    if (!tab || len == 1)
        return;

    partition(tab, 0, len - 1);
}
