#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *str = calloc(10, sizeof(char));
    const char *str2 = "Hello World!";

    for (int i = 0; i < 13; i++)
        str[i] = str2[i];

    printf("%s\n", str);
    return 0;
}
