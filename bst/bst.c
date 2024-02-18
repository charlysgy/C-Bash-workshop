#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

struct bst_node *create_node(int value)
{
    struct bst_node *node = calloc(1, sizeof(struct bst_node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct bst_node *add_node(struct bst_node *tree, int value)
{
    if (!tree)
        return create_node(value);
    if (tree->data < value)
        tree->right = add_node(tree->right, value);

    if (value < tree->data)
        tree->left = add_node(tree->left, value);

    return tree;
}

struct bst_node *min_left(struct bst_node *tree)
{
    if (tree->right)
        return min_left(tree->right);
    return tree;
}

struct bst_node *delete_node(struct bst_node *tree, int value)
{
    if (!tree)
        return NULL;

    if (value < tree->data)
    {
        tree->left = delete_node(tree->left, value);
    }
    else if (value > tree->data)
    {
        tree->right = delete_node(tree->right, value);
    }

    else
    {
        if (!tree->left && !tree->right)
        {
            free(tree);
            return NULL;
        }
        else if (!tree->left)
        {
            struct bst_node *tmp = tree->right;
            free(tree);
            return tmp;
        }
        else if (!tree->right)
        {
            struct bst_node *tmp = tree->left;
            free(tree);
            return tmp;
        }
        struct bst_node *min = min_left(tree->left);
        tree->data = min->data;
        tree->left = delete_node(tree->left, tree->data);
    }

    return tree;
}

const struct bst_node *find(const struct bst_node *tree, int value)
{
    if (!tree)
        return NULL;

    if (value < tree->data)
        return find(tree->left, value);

    if (tree->data < value)
        return find(tree->right, value);

    return tree;
}

void free_bst(struct bst_node *tree)
{
    if (!tree)
        return;

    free_bst(tree->left);
    free_bst(tree->right);

    free(tree);
}
