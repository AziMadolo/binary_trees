#include "binary_trees.h"
#include "limits.h"

/**
 * calc_height - Calculates the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree.
 */
size_t calc_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 0;

	size_t left_height = calc_height(tree->left);
	size_t right_height = calc_height(tree->right);

	return (left_height > right_height ? left_height : right_height) + 1;
}

/**
 * is_avl_tree - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @min: The minimum value allowed for nodes in the tree.
 * @max: The maximum value allowed for nodes in the tree.
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise.
 */
int is_avl_tree(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return 1;

	if (tree->n < min || tree->n > max)
		return 0;

	size_t left_height = calc_height(tree->left);
	size_t right_height = calc_height(tree->right);
	size_t height_diff = left_height > right_height ? left_height - right_height : right_height - left_height;

	if (height_diff > 1)
		return 0;

	return is_avl_tree(tree->left, min, tree->n - 1) && is_avl_tree(tree->right, tree->n + 1, max);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 0;

	return is_avl_tree(tree, INT_MIN, INT_MAX);
}


