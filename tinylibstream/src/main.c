#include <stdio.h>
#include <stdlib.h>

#include "libstream.h"

int main()
{
    // Test lbs_fopen
    struct stream *file = lbs_fopen("text.txt", "r+");
    if (file)
    {
        printf("lbs_fopen success!\n");
    }
    else
    {
        printf("lbs_fopen failed!\n");
        return 1;
    }

    // Try to read 5 char of the file using lbs_fgetc
    // then write Hello World with lbs_fputc
    // then flush the buffer with lbs_fflush
    // then close the file with lbs_fclose

    for (int i = 0; i < 5; ++i)
    {
        int c = lbs_fgetc(file);
        if (c != EOF)
        {
            printf("lbs_fgetc success! Read character: %c\n", c);
        }
        else
        {
            printf("lbs_fgetc failed!\n");
            return 1;
        }
    }

    file->buffering_mode = STREAM_BUFFERED;
    printf("Buffered size: %zu\n", file->buffered_size);

    const char *s = "Hello World how are you doing today ? \n";

    for (int i = 0; i < 40; i++)
    {
        lbs_fputc((int)s[i], file);
        printf("Buffered size: %zu\n", file->buffered_size);
    }

    int result = lbs_fputc('A', file);
    if (result != EOF)
    {
        printf("lbs_fputc success! Wrote character: %c\n", result);
    }
    else
    {
        printf("lbs_fputc failed!\n");
        return 1;
    }
    printf("Buffered size: %zu\n", file->buffered_size);

    // Test lbs_fflush
    if (lbs_fflush(file) == 0)
    {
        printf("lbs_fflush success!\n");
    }
    else
    {
        printf("lbs_fflush failed!\n");
        return 1;
    }

    // Test lbs_fclose
    if (lbs_fclose(file) == 0)
    {
        printf("lbs_fclose success!\n");
    }
    else
    {
        printf("lbs_fclose failed!\n");
        return 1;
    }

    return 0;
}