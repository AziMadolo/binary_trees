#include "binary_trees.h"

/**
 * calc_tree_height - Calculates the height of a binary tree.
 * @node: A pointer to the current node of the tree.
 *
 * Return: The height of the tree rooted at the given node.
 */
size_t calc_tree_height(const binary_tree_t *node)
{
    if (node)
    {
        size_t left_height = 0, right_height = 0;

        if (node->left)
            left_height = 1 + calc_tree_height(node->left);

        if (node->right)
            right_height = 1 + calc_tree_height(node->right);

        return (left_height > right_height ? left_height : right_height);
    }

    return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    return calc_tree_height(tree);
}

