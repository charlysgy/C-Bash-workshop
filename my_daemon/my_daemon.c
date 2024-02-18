#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void handler_1(int signum)
{
    static int signals = 0;
    static int generation = 0;
    signals++;

    if (signum == SIGUSR1)
        printf("Received %d signals.\n", signals);
    fflush(stdout);
    if (signum == SIGUSR2)
        printf("Current generation: %d\n", generation);
    fflush(stdout);
    if (signum == SIGTERM)
    {
        pid_t cpid = fork();
        if (!cpid)
        {
            signals = 0;
            generation++;
        }
        else
            exit(0);
    }
    if (signum == SIGINT)
    {
        fflush(stdout);
        exit(0);
    }
}

int main(void)
{
    pid_t cpid = fork();
    if (cpid)
        exit(0);

    struct sigaction sa;
    sa.sa_flags = 0; // Nothing special to do
    sa.sa_handler = handler_1;
    // Initialize mask
    if (sigemptyset(&sa.sa_mask) < 0)
    {
        // Handle error here
    }
    if (sigaction(SIGUSR1, &sa, NULL) < 0)
    {
        // Handle error here
    }
    if (sigaction(SIGUSR2, &sa, NULL) < 0)
    {
        // Handle error here
    }
    if (sigaction(SIGTERM, &sa, NULL) < 0)
    {
        // Handle error here
    }
    if (sigaction(SIGINT, &sa, NULL) < 0)
    {
        // Handle error here
    }
    while (1)
        continue;
}
