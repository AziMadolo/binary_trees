#include "binary_trees.h"

/**
 * heapify_up - Restores the Max Binary Heap property by moving the
 * new node up the tree if necessary.
 * @node: Pointer to the node to be moved up.
 */
void heapify_up(heap_t *node) {
    int tmp;
    while (node->parent && node->n > node->parent->n) {
        tmp = node->n;
        node->n = node->parent->n;
        node->parent->n = tmp;
        node = node->parent;
    }
}

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: A double pointer to the root node of the Heap to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value) {
    heap_t *new_node, *parent;

    if (!root)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!(*root)) {
        *root = new_node;
        return (new_node);
    }

    parent = *root;
    while (1) {
        if (parent->left == NULL) {
            parent->left = new_node;
            new_node->parent = parent;
            break;
        } else if (parent->right == NULL) {
            parent->right = new_node;
            new_node->parent = parent;
            break;
        } else {
            if (binary_tree_size(parent->left) <= binary_tree_size(parent->right))
                parent = parent->left;
            else
                parent = parent->right;
        }
    }

    heapify_up(new_node);
    return (new_node);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Tree to measure the size of.
 *
 * Return: Size of the tree, 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree) {
    if (!tree)
        return (0);

    return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void) {
    heap_t *root;
    heap_t *node;

    root = NULL;
    node = heap_insert(&root, 98);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 402);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 12);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 46);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 128);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 256);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 512);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 50);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    return (0);
}

