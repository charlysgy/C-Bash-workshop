#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

int replace_line(const char *file_in, const char *file_out, const char *content,
                 int n)
{
    FILE *in = fopen(file_in, "r");
    FILE *out = fopen(file_out, "w");

    if (!in || !out)
        return -1;

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;

    while ((read = getline(&line, &len, in)) != -1)
    {
        if (i++ == n)
            fputs(content, out);
        else
            fputs(line, out);
    }

    if (line)
        free(line);

    fclose(in);
    fclose(out);

    if (i < n)
        return 1;
    return 0;
}
