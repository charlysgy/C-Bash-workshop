#include "my_c_tail.h"

#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void add_in_queue(unsigned char **lines, unsigned char *line,
                         int lines_size)
{
    if (lines_size > 0)
        free(lines[lines_size - 1]);
    for (int i = lines_size; i > 1; i--)
    {
        lines[i - 1] = lines[i - 2];
    }

    lines[0] = line;
}

static void display_lines(unsigned char **lines, int n)
{
    char nl = '\n';
    for (int i = 0; i < n; i++)
    {
        if (!lines[n - i - 1])
            continue;
        int j = 0;
        while (lines[n - i - 1][j] >= 32)
            write(STDOUT_FILENO, &lines[n - i - 1][j++], 1);
        write(STDOUT_FILENO, &nl, 1);
        free(lines[n - i - 1]);
    }
}

void stdintail(unsigned int n)
{
    if (n == 0)
        return;
    unsigned char **lines = calloc(n, sizeof(unsigned char *));
    unsigned char *line = NULL;
    unsigned char c;
    int len = 0;
    int max_len = 1000;
    while (read(STDIN_FILENO, &c, 1))
    {
        if (!line)
            line = calloc(max_len, sizeof(unsigned char));
        if (c != '\n')
        {
            line[len] = c;
            len++;
            if (len == max_len)
            {
                max_len *= 2;
                line = realloc(line, max_len * sizeof(unsigned char));
            }
            c = ' ';
        }
        else
        {
            line[len] = '\0';
            len = 0;
            add_in_queue(lines, line, n);
            line = NULL;
        }
    }

    if (line)
    {
        line[len] = '\0';
        add_in_queue(lines, line, n);
    }

    display_lines(lines, n);
    free(lines);
}
