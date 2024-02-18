int binary_search(const int vec[], int size, int elt)
{
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        int pivot = (start + end) / 2;

        if (vec[pivot] == elt)
            return pivot;

        if (elt > vec[pivot])
            start = pivot + 1;

        else
            end = pivot - 1;
    }

    if (start == end && vec[start] == elt)
        return start;

    return -1;
}
