#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

int dlist_get(const struct dlist *list, size_t index)
{
    if (index > list->size - 1 || !list->head)
        return -1;

    if (index >= list->size / 2)
    {
        struct dlist_item *tmp = list->tail;
        for (int i = list->size - index - 1; i > 0; i--)
            tmp = tmp->prev;

        return tmp->data;
    }

    struct dlist_item *tmp = list->head;
    for (; index > 0; index--)
        tmp = tmp->next;

    return tmp->data;
}

void setup_inserted(struct dlist_item *item, struct dlist_item *old)
{
    item->next = old;
    item->prev = old->prev;
    item->prev->next = item;
    item->next->prev = item;
}

int dlist_insert_at(struct dlist *list, int element, size_t index)
{
    if (index > list->size || element < 0)
        return -1;

    if (index == list->size)
        return dlist_push_back(list, element);

    if (index == 0)
        return dlist_push_front(list, element);

    if (index > list->size / 2)
    {
        struct dlist_item *tmp = list->tail;
        for (int i = list->size - index - 1; i > 0; i--)
            tmp = tmp->prev;

        struct dlist_item *new = calloc(1, sizeof(struct dlist_item));

        new->data = element;
        setup_inserted(new, tmp);
    }
    else
    {
        struct dlist_item *tmp = list->head;
        for (; index > 0; index--)
            tmp = tmp->next;

        struct dlist_item *new = calloc(1, sizeof(struct dlist_item));

        new->data = element;
        setup_inserted(new, tmp);
    }

    list->size++;

    return 1;
}

int dlist_find(const struct dlist *list, int element)
{
    struct dlist_item *tmp = list->head;

    for (int i = 0; tmp; tmp = tmp->next, i++)
    {
        if (tmp->data == element)
            return i;
    }

    return -1;
}

void setup_removed(struct dlist_item *old)
{
    if (old->prev)
        old->prev->next = old->next;
    if (old->next)
        old->next->prev = old->prev;

    free(old);
}

int dlist_remove_at(struct dlist *list, size_t index)
{
    if (index >= list->size)
        return -1;

    struct dlist_item *item = list->head;

    for (size_t i = 0; item->next && i < index; i++)
        item = item->next;

    int to_return = item->data;

    if (index == 0)
        list->head = item->next;

    if (index == list->size - 1)
        list->tail = item->prev;

    setup_removed(item);

    list->size--;

    return to_return;
}

void dlist_clear(struct dlist *list)
{
    struct dlist_item *item = list->head;

    while (item)
    {
        struct dlist_item *tmp = item;
        item = item->next;
        free(tmp);
    }

    list->head = NULL;
    list->tail = NULL;

    list->size = 0;
}
