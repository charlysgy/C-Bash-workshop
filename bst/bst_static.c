#include "bst_static.h"

#include <stdlib.h>
#include <string.h>

struct bst *init(size_t capacity)
{
    struct bst *bst = calloc(1, sizeof(struct bst));

    bst->size = 0;
    bst->capacity = capacity;
    bst->data = calloc(bst->capacity, sizeof(struct value *));

    return bst;
}

void *realloc_zero(void *pBuffer, size_t oldSize, size_t newSize)
{
    void *pNew = realloc(pBuffer, newSize);
    if (newSize > oldSize && pNew)
    {
        size_t diff = newSize - oldSize;
        char *pNew_char = pNew;
        void *pStart = pNew_char + oldSize;
        memset(pStart, 0, diff);
    }
    return pNew;
}

void add(struct bst *tree, int value)
{
    if (!tree)
        return;

    size_t index = 1;
    while (index <= tree->capacity && tree->data[index - 1])
    {
        if (tree->data[index - 1]->val == value)
            return;
        if (tree->data[index - 1]->val < value)
            index = 2 * index + 1;
        else if (tree->data[index - 1]->val > value)
            index = 2 * index;
    }

    struct value *node = calloc(1, sizeof(struct value));

    node->val = value;

    tree->size++;
    if (index >= tree->capacity)
    {
        tree->data =
            realloc_zero(tree->data, tree->capacity * sizeof(struct value *),
                         sizeof(struct value *) * (tree->capacity * 2 + 2));
        tree->capacity = tree->capacity * 2 + 2;
    }

    tree->data[index - 1] = node;
}

int search(struct bst *tree, int value)
{
    size_t index = 1;
    while (index <= tree->capacity && tree->data[index - 1])
    {
        if (tree->data[index - 1]->val == value)
            return index - 1;
        if (tree->data[index - 1]->val < value)
            index = 2 * index + 1;
        else if (tree->data[index - 1]->val > value)
            index = 2 * index;
    }

    return -1;
}

void bst_free(struct bst *tree)
{
    for (size_t i = 0; i < tree->capacity; i++)
    {
        if (tree->data[i])
            free(tree->data[i]);
    }
    free(tree->data);
    free(tree);
}
