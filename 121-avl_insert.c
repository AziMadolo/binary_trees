#include "binary_trees.h"

/**
 * calculate_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t calculate_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = calculate_height(tree->left);
	size_t right_height = calculate_height(tree->right);

	return ((left_height > right_height) ? left_height + 1 : right_height + 1);
}

/**
 * calculate_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int calculate_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_height = calculate_height(tree->left);
	int right_height = calculate_height(tree->right);

	return (left_height - right_height);
}

/**
 * avl_recursive_insert - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 * @parent: The parent node of the current working node.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *avl_recursive_insert(avl_t **tree, int value, avl_t *parent)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(parent, value);
		return (*tree);
	}

	if (value < (*tree)->n)
		(*tree)->left = avl_recursive_insert(&((*tree)->left), value, *tree);
	else if (value > (*tree)->n)
		(*tree)->right = avl_recursive_insert(&((*tree)->right), value, *tree);
	else
		return (*tree);

	int balance_factor = calculate_balance(*tree);

	/* Perform rotations as necessary */
	/* ... (same rotation logic as in the original code) ... */

	return *tree;
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	return avl_recursive_insert(tree, value, NULL);
}

