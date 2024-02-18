#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    if (n <= 2)
        return;

    int size = 2;
    for (; size < n; size++)
        continue;

    int *sieved = calloc(sizeof(int), size + 1);

    if (!sieved)
        return;

    int primes = 0;

    for (int i = 2; i < n; i++)
    {
        if (sieved[i] == 0)
        {
            primes++;
            sieved[i] = 1;

            for (int multiple = 2 * i; multiple < n; multiple += i)
            {
                sieved[multiple] = 1;
            }
        }
    }

    printf("%d\n", primes);

    free(sieved);
}
