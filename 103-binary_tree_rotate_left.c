#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *pivot, *tmp;

    if (tree == NULL || tree->right == NULL)
        return (tree);

    pivot = tree->right;
    tmp = pivot->left;
    pivot->left = tree;
    tree->right = tmp;

    if (tmp != NULL)
        tmp->parent = tree;

    pivot->parent = tree->parent;
    tree->parent = pivot;

    if (pivot->parent != NULL)
    {
        if (pivot->parent->left == tree)
            pivot->parent->left = pivot;
        else
            pivot->parent->right = pivot;
    }

    return (pivot);
}

