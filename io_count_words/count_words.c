#include <stdio.h>

int count_words(const char *file_in)
{
    if (!file_in)
        return -1;

    FILE *file = fopen(file_in, "r");

    if (!file)
        return -1;

    int count = 0;
    int listening = 0;
    char c = '\0';

    while ((c = fgetc(file)) != EOF)
    {
        if ((c == ' ' || c == '\n' || c == '\t') && listening)
        {
            listening = 0;
            count++;
        }
        else if (c != ' ' && c != '\n' && c != '\t' && !listening)
        {
            listening = 1;
        }
    }
    if (listening)
        count++;

    fclose(file);
    return count;
}
