#include "vector.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct vector *vector_init(size_t n)
{
    struct vector *vector = calloc(1, sizeof(struct vector));

    vector->capacity = n;

    vector->data = calloc(n, sizeof(int));

    return vector;
}

void vector_destroy(struct vector *v)
{
    free(v->data);
    free(v);
}

struct vector *vector_resize(struct vector *v, size_t n)
{
    if (n == v->capacity)
        return v;

    v->data = realloc(v->data, n * sizeof(int));
    if (!v->data)
        return NULL;

    v->capacity = n;
    if (v->size > v->capacity)
        v->size = v->capacity;

    return v;
}

struct vector *vector_append(struct vector *v, int elt)
{
    if (!v)
        return NULL;

    if (v->size == v->capacity)
    {
        v->capacity *= 2;
        v->data = realloc(v->data, sizeof(int) * v->capacity);
        if (!v->data)
            return NULL;
    }

    v->data[v->size++] = elt;

    return v;
}

void vector_print(const struct vector *v)
{
    if (v && v->size > 0)
    {
        printf("%d", v->data[0]);

        for (size_t i = 1; i < v->size; i++)
        {
            printf(",%d", v->data[i]);
        }
    }
    printf("\n");
}

struct vector *vector_reset(struct vector *v, size_t n)
{
    free(v->data);

    v->size = 0;
    v->capacity = n;
    v->data = calloc(n, sizeof(int));

    if (!v->data)
        return NULL;

    return v;
}

struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    if (!v || i > v->size)
        return NULL;

    if (v->size == v->capacity)
    {
        v->capacity *= 2;
        v->data = realloc(v->data, v->capacity * sizeof(int));
    }

    v->size++;
    int tmp = elt;
    while (i < v->size)
    {
        int tmp2 = v->data[i];
        v->data[i] = tmp;
        tmp = tmp2;
        i++;
    }

    return v;
}

struct vector *vector_remove(struct vector *v, size_t i)
{
    if (!v || i > v->size)
        return NULL;

    v->size--;
    while (i < v->size)
    {
        v->data[i] = v->data[i + 1];
        i++;
    }

    if (v->size < v->capacity / 2)
    {
        v->capacity /= 2;
        v->data = realloc(v->data, v->capacity * sizeof(int));
    }

    if (!v->data)
        return NULL;
    return v;
}
