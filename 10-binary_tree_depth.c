#include "binary_trees.h"

/**
 * get_tree_depth - Helper function to calculate the depth of a binary tree node.
 * @node: A pointer to the node to measure the depth.
 *
 * Return: Depth of the node.
 */
static size_t get_tree_depth(const binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return 0;

	return 1 + get_tree_depth(node->parent);
}

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: If tree is NULL, your function must return 0, else return the depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return get_tree_depth(tree);
}

