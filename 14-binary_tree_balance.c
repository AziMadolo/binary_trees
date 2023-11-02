#include "binary_trees.h"

/**
 * calculate_height - Calculates the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree.
 */
size_t calculate_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    size_t left_height = calculate_height(tree->left);
    size_t right_height = calculate_height(tree->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    int left_height = calculate_height(tree->left);
    int right_height = calculate_height(tree->right);

    return left_height - right_height;
}

