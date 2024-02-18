#include "dlist.h"

unsigned int dlist_levenshtein(struct dlist *list1, struct dlist *list2)
{
    int tmp = list1->size - list2->size;
    unsigned int dist = tmp < 0 ? -tmp : tmp;

    struct dlist_item *tmp1 = list1->head;
    struct dlist_item *tmp2 = list2->head;
    while (tmp1 && tmp2)
    {
        if (tmp1->data != tmp2->data)
        {
            dist += 1;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    return dist;
}
