#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

size_t fifo_size(struct fifo *fifo)
{
    return fifo->size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    struct list *tail = calloc(1, sizeof(struct list));

    if (!tail)
        return;

    tail->next = NULL;
    tail->data = elt;

    if (!fifo->head)
    {
        fifo->head = tail;
        fifo->tail = tail;
    }
    else
    {
        fifo->tail->next = tail;
        fifo->tail = tail;
    }

    fifo->size++;
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    if (fifo_size(fifo) == 0)
        return;

    struct list *head = fifo->head;

    fifo->head = head->next;

    free(head);

    fifo->size--;
}

void fifo_print(const struct fifo *fifo)
{
    if (!fifo->head)
        return;

    struct list *tmp = fifo->head;

    while (tmp)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}
