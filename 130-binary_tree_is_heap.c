#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * is_max_heap - Checks if the given binary tree is a max heap.
 * @tree: Pointer to the root of the binary tree.
 * @max_value: The maximum value allowed for a node in the max heap.
 * Return: 1 if the tree is a max heap, 0 otherwise.
 */
int is_max_heap(const binary_tree_t *tree, int max_value)
{
    if (!tree)
        return 1;

    if (tree->n > max_value)
        return 0;

    return is_max_heap(tree->left, tree->n) && is_max_heap(tree->right, tree->n);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a max heap.
 * @tree: Pointer to the root of the binary tree.
 * Return: 1 if the tree is a max heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    int is_complete = binary_tree_is_complete(tree);

    if (!tree || !is_complete)
        return 0;

    return is_max_heap(tree, INT_MAX);
}

