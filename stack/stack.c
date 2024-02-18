#include "stack.h"

#include <stdlib.h>

struct stack *stack_push(struct stack *s, int e)
{
    struct stack *top = calloc(sizeof(struct stack), 1);

    if (!top)
        return s;

    top->data = e;
    top->next = s;

    return top;
}

struct stack *stack_pop(struct stack *s)
{
    if (!s)
        return NULL;

    struct stack *res = s->next;
    s->next = NULL;
    free(s);

    return res;
}

int stack_peek(struct stack *s)
{
    return s->data;
}
