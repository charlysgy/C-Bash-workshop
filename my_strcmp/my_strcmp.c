int my_strcmp(const char *s1, const char *s2)
{
    int index = 0;
    for (; s1[index] != '\0' && s2[index] != '\0'; index++)
    {
        if (s1[index] < s2[index])
            return -1;

        if (s1[index] > s2[index])
            return 1;
    }

    if (s1[index] != '\0')
        return 1;

    if (s2[index] != '\0')
        return -1;

    return 0;
}
