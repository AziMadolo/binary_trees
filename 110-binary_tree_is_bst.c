#include "binary_trees.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * isBSTHelper - Checks if a binary tree is a valid binary search tree.
 * @node: A pointer to the current node in the tree.
 * @min_val: The minimum value a node can have in the subtree rooted at @node.
 * @max_val: The maximum value a node can have in the subtree rooted at @node.
 *
 * Return: 1 if the subtree rooted at @node is a valid BST, 0 otherwise.
 */
int isBSTHelper(const binary_tree_t *node, int min_val, int max_val)
{
	if (node != NULL)
	{
		if (node->n < min_val || node->n > max_val)
			return 0;
		return isBSTHelper(node->left, min_val, node->n - 1) &&
		       isBSTHelper(node->right, node->n + 1, max_val);
	}
	return 1;
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid BST, and 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 0;
	return isBSTHelper(tree, INT_MIN, INT_MAX);
}

/**
 * binary_tree_node - Creates a new binary tree node
 * @parent: Pointer to the parent node
 * @value: Value to be put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return NULL;

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_print(tree->left);
		printf("%d\n", tree->n);
		binary_tree_print(tree->right);
	}
}

int main(void)
{
	binary_tree_t *root;
	int bst;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 128);
	root->left->right = binary_tree_node(root->left, 54);
	root->right->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 10);

	binary_tree_print(root);
	bst = binary_tree_is_bst(root);
	printf("Is %d BST: %d\n", root->n, bst);
	bst = binary_tree_is_bst(root->left);
	printf("Is %d BST: %d\n", root->left->n, bst);

	root->right->left = binary_tree_node(root->right, 97);
	binary_tree_print(root);
	bst = binary_tree_is_bst(root);
	printf("Is %d BST: %d\n", root->n, bst);
	return (0);
}

