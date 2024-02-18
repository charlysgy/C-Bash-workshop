#include "list.h"

#include <stdlib.h>
#include <string.h>

struct list *list_prepend(struct list *list, const void *value,
                          size_t data_size)
{
    struct list *new = calloc(1, sizeof(struct list));

    if (!new)
        return NULL;

    new->data = calloc(1, data_size);

    memcpy(new->data, value, data_size);

    new->next = list;

    return new;
}

size_t list_length(struct list *list)
{
    size_t len = 0;

    while (list)
    {
        list = list->next;
        len++;
    }

    return len;
}

void list_destroy(struct list *list)
{
    while (list)
    {
        struct list *tmp = list;
        list = list->next;
        free(tmp->data);
        free(tmp);
    }
}
