#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Calculate the height of left and right subtrees */
	int left_height = binary_tree_height(tree->left);
	int right_height = binary_tree_height(tree->right);

	/* Check if the left and right subtrees have the same height */
	if (left_height == right_height)
	{
		/* If the left and right subtrees are NULL, it is a leaf node */
		if (tree->left == NULL && tree->right == NULL)
			return (1);

		/* Recursively check left and right subtrees */
		return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}

	return (0); /* If heights are not the same, it's not perfect */
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Height of the tree, 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	/* Compute the height of each subtree */
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/* Return the maximum of two heights, plus 1 for the current node */
	return (1 + (left_height > right_height ? left_height : right_height));
}

