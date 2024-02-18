#include "binary_tree.h"

#include <limits.h>
#include <stdio.h>

int size(const struct binary_tree *tree)
{
    if (!tree)
        return 0;

    return 1 + size(tree->left) + size(tree->right);
}

static int height_rec(const struct binary_tree *tree)
{
    if (!tree)
        return 0;

    int left = height(tree->left);
    int right = height(tree->right);

    return 1 + ((left > right) ? left : right);
}

int height(const struct binary_tree *tree)
{
    if (!tree)
        return -1;

    return height_rec(tree);
}

void dfs_print_prefix(const struct binary_tree *tree)
{
    if (!tree)
        return;

    printf("%d ", tree->data);
    dfs_print_prefix(tree->left);
    dfs_print_prefix(tree->right);
}

void dfs_print_infix(const struct binary_tree *tree)
{
    if (!tree)
        return;

    dfs_print_infix(tree->left);
    printf("%d ", tree->data);
    dfs_print_infix(tree->right);
}

void dfs_print_postfix(const struct binary_tree *tree)
{
    if (!tree)
        return;

    dfs_print_postfix(tree->left);
    dfs_print_postfix(tree->right);
    printf("%d ", tree->data);
}

int is_perfect(const struct binary_tree *tree)
{
    if (!tree)
        return 1;
    if (!tree->left && !tree->right)
        return 1;
    if (!tree->left || !tree->right)
        return 0;
    return is_perfect(tree->left) && is_perfect(tree->right);
}

static int is_complete_rec(const struct binary_tree *tree, int size, int index)
{
    if (index > size)
        return 0;

    if (!tree->left && !tree->right)
        return 1;

    int returned = 0;
    if (tree->left)
        returned += is_complete_rec(tree->left, size, index * 2);
    else if (tree->right)
        return 0;

    if (tree->right)
        returned += is_complete_rec(tree->right, size, 2 * index + 1);
    else
        returned++;

    if (returned != 2)
        return 0;
    return 1;
}

int is_complete(const struct binary_tree *tree)
{
    int len = size(tree);

    return is_complete_rec(tree, len, 1);
}

int is_degenerate(const struct binary_tree *tree)
{
    if (!tree)
        return 0;

    while (tree)
    {
        if (tree->left && tree->right)
            return 0;
        if (tree->left)
            tree = tree->left;
        else if (tree->right)
            tree = tree->right;
        else
            return 1;
    }
    return 1;
}

int is_full(const struct binary_tree *tree)
{
    if (!tree)
        return 0;

    if (tree->left && tree->right)
    {
        if (is_full(tree->left) == 1 && is_full(tree->right) == 1)
            return 1;
        return 0;
    }
    if (!tree->left && !tree->right)
        return 1;

    return 0;
}

static int is_bst_rec(const struct binary_tree *tree, int min, int max)
{
    if (!tree)
        return 1;

    if (tree->data <= min || tree->data >= max)
        return 0;

    return is_bst_rec(tree->left, min, tree->data) == 1
        && is_bst_rec(tree->right, tree->data, max) == 1;
}

int is_bst(const struct binary_tree *tree)
{
    if (!tree)
        return 0;

    return is_bst_rec(tree, INT_MIN, INT_MAX);
}
