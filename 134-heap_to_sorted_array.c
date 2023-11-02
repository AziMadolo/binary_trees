#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * calculate_tree_size - helper function to calculate the size of a binary tree
 * @node: pointer to the current node
 *
 * Return: size of the tree rooted at the given node
 */
static size_t calculate_tree_size(const binary_tree_t *node)
{
    if (!node)
        return 0;

    return 1 + calculate_tree_size(node->left) + calculate_tree_size(node->right);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: pointer to array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int i, *sorted_array = NULL;

    if (!heap || !size)
        return NULL;

    *size = calculate_tree_size(heap);

    sorted_array = malloc(sizeof(int) * (*size));
    if (!sorted_array)
        return NULL;

    for (i = *size - 1; i >= 0; i--)
        sorted_array[i] = heap_extract(&heap);

    return sorted_array;
}

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    heap_t *tree;
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22, 98, 1, 62, 95
    };
    size_t n = sizeof(array) / sizeof(array[0]);
    int *sorted;
    size_t sorted_size;

    print_array(array, n);
    tree = array_to_heap(array, n);
    if (!tree)
        return (1);
    binary_tree_print(tree);
    sorted = heap_to_sorted_array(tree, &sorted_size);
    print_array(sorted, sorted_size);
    free(sorted);
    return (0);
}

