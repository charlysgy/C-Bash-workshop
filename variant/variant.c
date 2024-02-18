#include "variant.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void variant_display(const struct variant *e)
{
    switch (e->type)
    {
    case TYPE_INT:
        printf("%d\n", e->value.int_v);
        break;

    case TYPE_FLOAT:
        printf("%f\n", e->value.float_v);
        break;

    case TYPE_CHAR:
        printf("%c\n", e->value.char_v);
        break;

    case TYPE_STRING:
        printf("%s\n", e->value.str_v);

    default:
        break;
    }
}

bool variant_equal(const struct variant *left, const struct variant *right)
{
    if (!left && !right)
        return true;

    if (!left || !right)
        return false;

    switch (left->type)
    {
    case TYPE_INT:
        return ((right->type == TYPE_INT)
                && left->value.int_v == right->value.int_v);

    case TYPE_FLOAT:
        return ((right->type == TYPE_FLOAT)
                && left->value.float_v == right->value.float_v);

    case TYPE_CHAR:
        return ((right->type == TYPE_CHAR)
                && left->value.char_v == right->value.char_v);

    case TYPE_STRING:
        if (right->type == TYPE_STRING)
        {
            int i = 0;
            for (; left->value.str_v[i] != '\0'; i++)
                if (left->value.str_v[i] != right->value.str_v[i])
                    return false;
            if (left->value.str_v[i] == right->value.str_v[i])
                return true;
            return false;
        }
        return false;

    default:
        return false;
    }
}

int variant_find(const struct variant *array, size_t len, enum type type,
                 union type_any value)
{
    for (size_t i = 0; i < len; i++)
    {
        if (array[i].type == type)
        {
            switch (type)
            {
            case TYPE_INT:
                if (array[i].value.int_v == value.int_v)
                    return i;
                break;
            case TYPE_FLOAT:
                if (array[i].value.float_v == value.float_v)
                    return i;
                break;
            case TYPE_CHAR:
                if (array[i].value.char_v == value.char_v)
                    return i;
                break;
            case TYPE_STRING:
                if (strcmp(array[i].value.str_v, value.str_v) == 0)
                    return i;
                break;
            default:
                break;
            }
        }
    }

    return -1;
}

float variant_sum(const struct variant *array, size_t len)
{
    float sum = 0;
    for (; len > 0; len--)
    {
        if (array[len - 1].type == TYPE_FLOAT)
            sum += array[len - 1].value.float_v;
        else if (array[len - 1].type == TYPE_INT)
            sum += array[len - 1].value.int_v;
    }

    return sum;
}
