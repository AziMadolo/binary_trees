#include "binary_trees.h"

/**
 * create_avl_node - Creates a new AVL node.
 * @value: The value to be stored in the new node.
 *
 * Return: A pointer to the newly created AVL node, or NULL upon failure.
 */
static avl_t *create_avl_node(int value)
{
	avl_t *new_node = malloc(sizeof(avl_t));
	
	if (new_node)
	{
		new_node->n = value;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->parent = NULL;
	}
	
	return new_node;
}

/**
 * insert_avl_node - Inserts a value into the AVL tree.
 * @tree: A pointer to the root of the AVL tree.
 * @value: The value to be inserted.
 *
 * Return: A pointer to the updated AVL tree, or NULL upon failure.
 */
static avl_t *insert_avl_node(avl_t *tree, int value)
{
	if (tree == NULL)
		return create_avl_node(value);

	if (value < tree->n)
	{
		tree->left = insert_avl_node(tree->left, value);
		tree->left->parent = tree;
	}
	else if (value > tree->n)
	{
		tree->right = insert_avl_node(tree->right, value);
		tree->right->parent = tree;
	}

	return tree;
}

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created AVL, or NULL upon failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i;

	if (array == NULL)
		return NULL;

	for (i = 0; i < size; i++)
	{
		tree = insert_avl_node(tree, array[i]);
		if (tree == NULL)
			return NULL;
	}

	return tree;
}

