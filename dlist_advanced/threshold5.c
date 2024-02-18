#include "dlist.h"

void swap(struct dlist_item *item1, struct dlist_item *item2)
{
    int int_tmp = item1->data;
    item1->data = item2->data;
    item2->data = int_tmp;
}

void dlist_sort(struct dlist *list)
{
    if (!list || list->size <= 1)
        return;

    for (size_t i = 0; i < list->size - 1; i++)
    {
        struct dlist_item *tmp = list->head;
        for (size_t j = 0; tmp && j < list->size - 1; j++)
        {
            if (tmp->data > tmp->next->data)
                swap(tmp, tmp->next);
            tmp = tmp->next;
        }
    }
}

void dlist_merge(struct dlist *list1, struct dlist *list2)
{
    dlist_concat(list1, list2);
    dlist_sort(list1);
}
