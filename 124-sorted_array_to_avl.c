#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * avl_tree_recursion - recursive function to create AVL tree
 *
 * @array: input array of integers
 * @start: starting index of the array
 * @end: ending index of the array
 * Return: pointer to the created AVL tree
 */
avl_t *avl_tree_recursion(int *array, size_t start, size_t end)
{
    if (start > end)
        return NULL;

    size_t middle = (start + end) / 2;
    avl_t *node = binary_tree_node(NULL, array[middle]);

    if (node == NULL)
        return NULL;

    node->left = avl_tree_recursion(array, start, middle - 1);
    node->right = avl_tree_recursion(array, middle + 1, end);

    return node;
}

/**
 * sorted_array_to_avl - creates AVL tree from sorted array
 *
 * @array: input array of integers
 * @size: size of the array
 * Return: pointer to the root of the AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return NULL;

    return avl_tree_recursion(array, 0, size - 1);
}

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Size of the array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    for (i = 0; i < size; ++i)
        printf("(%03d)", array[i]);
    printf("\n");
}

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    avl_t *tree;
    int array[] = {
        1, 2, 20, 21, 22, 32, 34, 47, 62, 68,
        79, 84, 87, 91, 95, 98
    };
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = sorted_array_to_avl(array, n);
    if (!tree)
        return (1);
    print_array(array, n);
    binary_tree_print(tree);
    return (0);
}

