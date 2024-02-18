#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int rotx(int key)
{
    char c;
    int rc = read(STDIN_FILENO, &c, 1);
    while (rc == 1)
    {
        char new = c;
        if ('a' <= c && c <= 'z')
        {
            new = (c - 'a' + key) % 26;
            if (new < 0)
                new += 26;
            new += 'a';
        }
        else if ('A' <= c && c <= 'Z')
        {
            new = (c - 'A' + key) % 26;
            if (new < 0)
                new += 26;
            new += 'A';
        }
        else if ('0' <= c && c <= '9')
        {
            new = (c - '0' + key) % 10;
            if (new < 0)
                new += 10;
            new += '0';
        }
        if (write(STDOUT_FILENO, &new, 1) != 1)
            return 0;

        rc = read(STDIN_FILENO, &c, 1);
    }

    if (rc < 0)
        return 1;
    return 0;
}

int main(int argc, char **argv)
{
    return rotx(atoi(argv[argc - 1]));
}
