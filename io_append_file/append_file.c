#include <stddef.h>
#include <stdio.h>

int append_file(const char *file_in, const char *content)
{
    if (!content || !file_in)
        return -1;

    FILE *file = fopen(file_in, "a");

    fprintf(file, "%s", content);

    fclose(file);
    return 0;
}
