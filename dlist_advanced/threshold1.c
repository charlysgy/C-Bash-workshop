#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

struct dlist *dlist_init(void)
{
    struct dlist *list = calloc(1, sizeof(struct dlist));

    if (!list)
        return NULL;

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

int dlist_push_front(struct dlist *list, int element)
{
    if (element < 0)
        return 0;

    struct dlist_item *item = calloc(1, sizeof(struct dlist_item));

    if (!item)
        return 0;

    item->data = element;
    item->next = NULL;
    item->prev = NULL;

    if (!list->head)
    {
        list->head = item;
        list->tail = item;
        list->size++;
    }
    else
    {
        item->next = list->head;
        item->prev = NULL;
        list->head->prev = item;
        list->head = item;
        list->size++;
    }

    return 1;
}

void dlist_print(const struct dlist *list)
{
    struct dlist_item *tmp = list->head;

    for (size_t i = 0; i < list->size; i++)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}

int dlist_push_back(struct dlist *list, int element)
{
    if (element < 0)
        return 0;

    struct dlist_item *item = calloc(1, sizeof(struct dlist_item));

    if (!item)
        return 0;

    item->data = element;
    item->next = NULL;
    item->prev = NULL;

    if (!list->tail)
    {
        list->head = item;
        list->tail = item;
        list->size++;
    }
    else
    {
        item->prev = list->tail;
        item->next = NULL;
        list->tail->next = item;
        list->tail = item;
        list->size++;
    }

    return 1;
}

size_t dlist_size(const struct dlist *list)
{
    return list->size;
}
