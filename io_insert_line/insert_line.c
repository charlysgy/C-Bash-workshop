#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

int add_len(const char *content)
{
    int len = 0;
    while (*content != '\0')
    {
        if (*content == '\n')
            len++;
        content += 1;
    }
    return len;
}

// Get the number of lines in a file
int get_lines(const char *fileout)
{
    FILE *file = fopen(fileout, "r");
    if (!file)
        return -1;

    char *line = NULL;
    size_t size = 0;
    int len = 0;
    while (getline(&line, &size, file) != -1)
        len++;

    fclose(file);
    if (line)
        free(line);

    return len;
}

int insert_line(const char *file_in, const char *file_out, const char *content,
                size_t n)
{
    if (!file_in || !file_out || !content)
        return -1;

    FILE *filein = fopen(file_in, "r");
    FILE *fileout = fopen(file_out, "w");

    if (!filein || !fileout)
        return -1;

    char *line = NULL;
    size_t size = 0;
    size_t len = 0;
    while (len != n && getline(&line, &size, filein) != -1)
    {
        fputs(line, fileout);
        len++;
    }

    while (len < n)
    {
        fputs("\n", fileout);
        len++;
    }

    fputs(content, fileout);

    while (getline(&line, &size, filein) != -1)
        fputs(line, fileout);

    fclose(filein);
    fclose(fileout);

    if (line)
        free(line);

    return get_lines(file_out);
}

int main(void)
{
    const char *file_in = "file";
    const char *file_out = "out";
    const char *content = "moi\n";
    size_t n = 0;

    int len = insert_line(file_in, file_out, content, n);
    if (len == -1)
        return EXIT_FAILURE;

    printf("Number of lines: %d\n", len);

    return EXIT_SUCCESS;
}
