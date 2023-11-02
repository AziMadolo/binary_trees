#include "binary_trees.h"

/**
 * create_node - Creates a new BST node.
 * @value: The value to be inserted into the new node.
 *
 * Return: A pointer to the newly created node, or NULL upon failure.
 */
bst_t *create_node(int value)
{
    bst_t *new_node = malloc(sizeof(bst_t));
    if (new_node == NULL)
        return (NULL);
    new_node->n = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
}

/**
 * array_to_bst - Builds a binary search tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created BST, or NULL upon failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
    bst_t *tree = NULL;
    size_t i;

    if (array == NULL)
        return (NULL);

    for (i = 0; i < size; i++)
    {
        bst_t *node = create_node(array[i]);
        if (node == NULL)
        {
            /* Handle memory allocation failure */
            while (tree != NULL)
            {
                bst_remove(&tree, tree->n);
            }
            return (NULL);
        }
        if (tree == NULL)
        {
            tree = node;
        }
        else
        {
            bst_insert(&tree, array[i]);
        }
    }

    return (tree);
}

