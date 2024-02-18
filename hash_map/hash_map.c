#include "hash_map.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash_map *hash_map_init(size_t size)
{
    struct hash_map *map = calloc(1, sizeof(struct hash_map));

    if (!map)
        return NULL;

    map->size = size;

    map->data = calloc(size, sizeof(struct pair_list));
    if (!map->data)
        return NULL;

    return map;
}

bool hash_map_insert(struct hash_map *hash_map, const char *key, char *value,
                     bool *updated)
{
    if (!hash_map || hash_map->size == 0)
        return false;

    size_t h = hash(key);

    if (h > hash_map->size)
        h = h % hash_map->size;

    struct pair_list *tmp = hash_map->data[h];
    while (tmp)
    {
        if (strcmp(tmp->key, key) == 0)
        {
            *updated = true;
            tmp->value = value;
            return true;
        }
        tmp = tmp->next;
    }

    struct pair_list *new = calloc(1, sizeof(struct pair_list));

    new->key = key;
    new->value = value;
    new->next = hash_map->data[h];
    hash_map->data[h] = new;

    *updated = false;
    return true;
}

void hash_map_free(struct hash_map *hash_map)
{
    if (!hash_map)
        return;

    for (; hash_map->size > 0; hash_map->size--)
    {
        struct pair_list *tmp = hash_map->data[hash_map->size - 1];

        while (tmp)
        {
            struct pair_list *tmp2 = tmp;
            tmp = tmp->next;
            free(tmp2);
        }
    }
    free(hash_map->data);
    free(hash_map);
}

void hash_map_dump(struct hash_map *hash_map)
{
    for (size_t i = 0; i < hash_map->size; i++)
    {
        struct pair_list *tmp = hash_map->data[i];

        if (tmp)
        {
            printf("%s: %s", tmp->key, tmp->value);
            tmp = tmp->next;
            while (tmp)
            {
                printf(", %s: %s", tmp->key, tmp->value);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
}

const char *hash_map_get(const struct hash_map *hash_map, const char *key)
{
    if (!hash_map || hash_map->size == 0)
        return NULL;

    size_t h = hash(key);

    if (h > hash_map->size)
        h = h % hash_map->size;

    struct pair_list *tmp = hash_map->data[h];

    while (tmp)
    {
        if (strcmp(key, tmp->key) == 0)
            return tmp->value;
        tmp = tmp->next;
    }

    return NULL;
}

bool hash_map_remove(struct hash_map *hash_map, const char *key)
{
    if (!hash_map || hash_map->size == 0)
        return false;

    size_t h = hash(key);

    if (h > hash_map->size)
        h = h % hash_map->size;

    struct pair_list *tmp = hash_map->data[h];
    struct pair_list *last = NULL;

    while (tmp)
    {
        if (strcmp(key, tmp->key) == 0)
        {
            if (last)
                last->next = tmp->next;
            else
                hash_map->data[h] = tmp->next;

            free(tmp);
            return true;
        }
        last = tmp;
        tmp = tmp->next;
    }

    return false;
}
