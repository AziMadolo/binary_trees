#include "binary_trees.h"
#include <stdlib.h>

/**
 * get_tree_height - Calculate the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t get_tree_height(const heap_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return 0;

	left_height = tree->left ? 1 + get_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + get_tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * get_tree_size - Calculate the size of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t get_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return 0;

	return 1 + get_tree_size(tree->left) + get_tree_size(tree->right);
}

/**
 * find_target_node - Find the target node for extraction
 * @tree: Pointer to the root node of the tree
 * @target_node: Double pointer to store the target node
 * @height: Height of the tree
 */
void find_target_node(heap_t *tree, heap_t **target_node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*target_node = tree;
	height--;

	find_target_node(tree->left, target_node, height);
	find_target_node(tree->right, target_node, height);
}

/**
 * heapify_down - Restore the max heap property after extraction
 * @root: Pointer to the heap root
 */
void heapify_down(heap_t *root)
{
	int value;
	heap_t *tmp1, *tmp2;

	if (!root)
		return;

	tmp1 = root;

	while (1)
	{
		if (!tmp1->left)
			break;

		tmp2 = (!tmp1->right || tmp1->left->n > tmp1->right->n) ? tmp1->left : tmp1->right;

		if (tmp1->n >= tmp2->n)
			break;

		value = tmp1->n;
		tmp1->n = tmp2->n;
		tmp2->n = value;
		tmp1 = tmp2;
	}
}

/**
 * heap_extract - Extract the root node from a Max Binary Heap
 * @root: Double pointer to the heap root
 * Return: Value of the extracted node
 **/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_root, *target_node;

	if (!root || !*root)
		return 0;

	heap_root = *root;
	value = heap_root->n;

	if (!heap_root->left && !heap_root->right)
	{
		free(heap_root);
		*root = NULL;
		return value;
	}

	find_target_node(heap_root, &target_node, get_tree_height(heap_root));
	heap_root->n = target_node->n;

	if (target_node->parent->left == target_node)
		target_node->parent->left = NULL;
	else
		target_node->parent->right = NULL;

	free(target_node);
	heapify_down(heap_root);
	*root = heap_root;
	return value;
}

