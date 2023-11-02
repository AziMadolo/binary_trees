#include "binary_trees.h"

/**
 * count_nodes_with_children - Counts nodes with at least one child in a binary tree.
 * @node: A pointer to the current node being checked.
 *
 * Return: Number of nodes with at least one child.
 */
size_t count_nodes_with_children(const binary_tree_t *node)
{
    size_t count = 0;

    if (node)
    {
        if (node->left != NULL || node->right != NULL)
            count++;

        count += count_nodes_with_children(node->left);
        count += count_nodes_with_children(node->right);
    }

    return count;
}

/**
 * binary_tree_nodes - Counts nodes with at least one child in a binary tree.
 * @tree: A pointer to the root node of the tree to count nodes with children.
 *
 * Return: If tree is NULL, the function must return 0, else return node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    return count_nodes_with_children(tree);
}

