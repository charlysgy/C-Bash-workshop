#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

void dlist_map_square(struct dlist *list)
{
    struct dlist_item *tmp = list->head;

    while (tmp)
    {
        tmp->data = tmp->data * tmp->data;
        tmp = tmp->next;
    }
}

void dlist_reverse(struct dlist *list)
{
    struct dlist_item *tmp = list->head;

    for (; tmp; tmp = tmp->prev)
    {
        struct dlist_item *tmp2 = tmp->next;
        tmp->next = tmp->prev;
        tmp->prev = tmp2;
    }

    tmp = list->head;
    list->head = list->tail;
    list->tail = tmp;
}

struct dlist *dlist_split_at(struct dlist *list, size_t index)
{
    if (index > list->size)
        return NULL;

    if (index == list->size || !list->head)
        return dlist_init();

    struct dlist *splitted = calloc(1, sizeof(struct dlist));

    if (index == 0)
    {
        splitted->head = list->head;
        splitted->tail = list->tail;
        splitted->size = list->size;
        list->size = 0;
        list->head = NULL;
        list->tail = NULL;
        return splitted;
    }
    struct dlist_item *tmp = list->head;

    splitted->size = list->size - index;
    list->size = index;

    for (; index > 0; index--, tmp = tmp->next)
        continue;

    list->tail = tmp->prev;
    splitted->head = tmp;

    if (tmp->prev)
        tmp->prev->next = NULL;
    tmp->prev = NULL;

    while (tmp->next)
        tmp = tmp->next;

    splitted->tail = tmp;

    return splitted;
}

void dlist_concat(struct dlist *list1, struct dlist *list2)
{
    list1->size += list2->size;

    if (!list1->head && list2->head)
    {
        list1->head = list2->head;
        list1->tail = list2->tail;
        list2->head = NULL;
        list2->tail = NULL;
        list2->size = 0;
        return;
    }
    else if (!list2->head)
    {
        return;
    }

    list1->tail->next = list2->head;
    list2->head->prev = list1->tail;
    list1->tail = list2->tail;
    list2->head = NULL;
    list2->tail = NULL;
    list2->size = 0;
}
