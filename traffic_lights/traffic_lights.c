#include "traffic_lights.h"

void init(unsigned char *light)
{
    *light = 0;
}

void turn_on(unsigned char *light, unsigned char light_num)
{
    unsigned char mask = 1 << (light_num - 1);

    *light = *light | mask;
}

void turn_off(unsigned char *light, unsigned char light_num)
{
    unsigned char mask = ~(1 << (light_num - 1));

    *light = *light & mask;
}

void next_step(unsigned char *light)
{
    unsigned char mask = 1 << 3;
    unsigned char remaining = *light & mask;

    *light = *light << 1;
    *light = *light | (remaining >> 3);
}

void reverse(unsigned char *light)
{
    *light = ~(*light);
}

void swap(unsigned char *l1, unsigned char *l2)
{
    unsigned char tmp = *l1;
    *l1 = *l2;
    *l2 = tmp;
}
