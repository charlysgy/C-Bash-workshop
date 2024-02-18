#include <stdlib.h>

#include "fifo.h"

struct fifo *fifo_init(void)
{
    struct fifo *fifo = calloc(1, sizeof(struct fifo));

    if (!fifo)
        return NULL;

    fifo->size = 0;
    fifo->head = NULL;
    fifo->tail = NULL;

    return fifo;
}

void fifo_clear(struct fifo *fifo)
{
    while (fifo->size > 0)
    {
        fifo_pop(fifo);
    }

    fifo->tail = NULL;
    fifo->head = NULL;
}

void fifo_destroy(struct fifo *fifo)
{
    fifo_clear(fifo);

    free(fifo);
}
