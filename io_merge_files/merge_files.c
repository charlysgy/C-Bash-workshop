#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

int merge_files(const char *file_1, const char *file_2)
{
    if (!file_1 || !file_2)
        return -1;

    FILE *file2 = fopen(file_2, "r");

    if (!file2)
        return -1;

    FILE *file1 = fopen(file_1, "a");

    if (!file1)
        return -1;

    char *line = NULL;
    size_t size = 0;

    while (getline(&line, &size, file2) > 0)
    {
        fputs(line, file1);
    }

    fclose(file1);
    fclose(file2);

    if (line)
        free(line);
    return 0;
}
