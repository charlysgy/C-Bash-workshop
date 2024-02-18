#include "complex.h"

#include <stdio.h>

void print_complex(struct complex a)
{
    printf("complex(%0.2f ", a.real);

    if (a.img < 0)
    {
        printf("- %0.2fi)\n", -a.img);
    }
    else
    {
        printf("+ %0.2fi)\n", a.img);
    }
}

struct complex neg_complex(struct complex a)
{
    struct complex neg = {
        -a.real,
        -a.img,
    };

    return neg;
}

struct complex add_complex(struct complex a, struct complex b)
{
    struct complex added = {
        a.real + b.real,
        a.img + b.img,
    };

    return added;
}

struct complex sub_complex(struct complex a, struct complex b)
{
    struct complex subed = {
        a.real - b.real,
        a.img - b.img,
    };
    return subed;
}

struct complex mul_complex(struct complex a, struct complex b)
{
    struct complex mult = {
        a.real * b.real - a.img * b.img,
        a.real * b.img + a.img * b.real,
    };

    return mult;
}

struct complex div_complex(struct complex a, struct complex b)
{
    int c2 = (b.real * b.real);
    int d2 = (b.img * b.img);

    struct complex div = {
        (a.real * b.real + a.img * b.img) / (c2 + d2),
        (a.img * b.real - a.real * b.img) / (c2 + d2),
    };

    return div;
}

int main(void)
{
    struct complex a = {
        -1,
        -5,
    };

    print_complex(a);
    print_complex(neg_complex(a));
}
