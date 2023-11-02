#include "binary_trees.h"

/**
 * find_binary_tree_sibling - Finds the sibling of a
 *                            node in a binary tree.
 * @node: A pointer to the node to find the sibling of.
 *
 * Return: If node is NULL or there is no sibling - NULL.
 *         Otherwise - a pointer to the sibling.
 */
binary_tree_t *find_binary_tree_sibling(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL)
        return (NULL);

    binary_tree_t *parent = node->parent;

    if (parent->left == node && parent->right != NULL)
        return (parent->right);
    else if (parent->right == node && parent->left != NULL)
        return (parent->left);
    else
        return (NULL);
}

