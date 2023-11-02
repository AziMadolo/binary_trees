#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current = *tree;
	bst_t *parent = NULL;
	bst_t *new_node;

	if (tree == NULL)
		return (NULL);

	/* Search for the appropriate position to insert the new node */
	while (current != NULL)
	{
		parent = current;
		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else
			return (NULL); /* Duplicates are not allowed in BST */
	}

	/* Create a new node and insert it at the appropriate position */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent == NULL)
		*tree = new_node; /* Tree is empty, new node becomes the root */
	else if (value < parent->n)
		parent->left = new_node; /* Insert as left child */
	else
		parent->right = new_node; /* Insert as right child */

	return (new_node);
}

