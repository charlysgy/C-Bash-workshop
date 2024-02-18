#include <stdio.h>

size_t get_file_size(FILE *fp)
{
    size_t len = 0;
    char c;

    while ((c = fgetc(fp)) != EOF)
    {
        len++;
    }

    return len;
}

int reverse_content(const char *file_in, const char *file_out)
{
    FILE *in = fopen(file_in, "r");
    FILE *out = fopen(file_out, "w");

    if (!in || !out)
        return -1;

    size_t size = get_file_size(in);

    for (int i = size - 1; i >= 0; i--)
    {
        fseek(in, i, SEEK_SET);
        fputc(fgetc(in), out);
    }

    fclose(in);
    fclose(out);

    return 0;
}
