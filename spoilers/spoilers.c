#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int spoilers(int fd)
{
    char c;

    char sp1 = '\n';
    char sp2 = '\n';

    int rc = read(fd, &c, 1);

    while (rc == 1)
    {
        if (c != ' ' && c != '\f' && c != '\r' && c != '\n' && c != '\t'
            && c != '\v' && c != '\0')
        {
            if (sp1 == '\n')
                sp1 = c;
            else
            {
                sp2 = sp1;
                sp1 = c;
            }
        }
        rc = read(fd, &c, 1);
    }

    if (rc != 0)
        return 1;

    if (sp1 == '\n' || sp2 == '\n')
    {
        write(STDERR_FILENO, "File is not long enough\n", 24);
        return 1;
    }
    else
    {
        write(STDOUT_FILENO, &sp2, 1);
        write(STDOUT_FILENO, &sp1, 1);
        write(STDOUT_FILENO, "\n", 1);
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(STDERR_FILENO, "Invalid number of arguments\n", 28);
        return 1;
    }
    int fd = open(argv[argc - 1], O_RDONLY);

    if (fd == -1)
    {
        write(STDERR_FILENO, "Could not open file\n", 20);
        return 1;
    }

    int rc = spoilers(fd);

    close(fd);

    return rc;
}
