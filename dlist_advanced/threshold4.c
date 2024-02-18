#include "dlist.h"

void dlist_shift(struct dlist *list, int offset)
{
    if (!list || list->size == 0 || list->size == 1 || offset == 0)
        return;

    int i = offset > 0 ? offset : -offset;
    for (; i > 0; i--)
    {
        if (offset > 0)
        {
            struct dlist_item *to_move = list->tail;
            list->tail = to_move->prev;
            list->tail->next = NULL;

            to_move->next = list->head;
            to_move->next->prev = to_move;
            to_move->prev = NULL;

            list->head = to_move;
        }

        else if (offset < 0)
        {
            struct dlist_item *to_move = list->head;
            list->head = to_move->next;
            list->head->prev = NULL;

            to_move->prev = list->tail;
            to_move->prev->next = to_move;
            to_move->next = NULL;

            list->tail = to_move;
        }
    }
}

int dlist_add_sort(struct dlist *list, int element)
{
    if (!list || element < 0)
        return -1;

    if (list->size == 0)
    {
        dlist_insert_at(list, element, 0);
        return 1;
    }

    struct dlist_item *tmp = list->head;

    size_t index = 0;
    while (tmp && tmp->data < element)
    {
        tmp = tmp->next;
        index++;
    }

    dlist_insert_at(list, element, index);
    return 1;
}

int dlist_remove_eq(struct dlist *list, int element)
{
    if (!list || element < 0 || list->size == 0)
        return 0;

    struct dlist_item *tmp = list->head;

    size_t index = 0;
    while (tmp && tmp->data != element)
    {
        tmp = tmp->next;
        index++;
    }

    if (index == list->size)
        return 0;

    if (dlist_remove_at(list, index) == -1)
        return 0;
    return 1;
}

struct dlist *dlist_copy(const struct dlist *list)
{
    if (!list)
        return NULL;

    struct dlist *new_list = dlist_init();

    struct dlist_item *tmp = list->head;

    while (tmp)
    {
        if (dlist_push_back(new_list, tmp->data) == 0)
            return NULL;
        tmp = tmp->next;
    }

    return new_list;
}
