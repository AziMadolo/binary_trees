#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * Finds the inorder successor of a node in a binary search tree.
 */
bst_t *find_inorder_successor(bst_t *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

/**
 * Deletes a node from a binary search tree.
 */
bst_t *delete_bst_node(bst_t *root, bst_t *node) {
    bst_t *parent = node->parent, *successor = NULL;

    if (node->left == NULL) {
        // No left child or both children absent
        if (parent != NULL && parent->left == node) {
            parent->left = node->right;
        } else if (parent != NULL) {
            parent->right = node->right;
        }
        if (node->right != NULL) {
            node->right->parent = parent;
        }
        free(node);
        return (parent == NULL ? node->right : root);
    } else if (node->right == NULL) {
        // Only left child present
        if (parent != NULL && parent->left == node) {
            parent->left = node->left;
        } else if (parent != NULL) {
            parent->right = node->left;
        }
        if (node->left != NULL) {
            node->left->parent = parent;
        }
        free(node);
        return (parent == NULL ? node->left : root);
    } else {
        // Two children present
        successor = find_inorder_successor(node->right);
        node->n = successor->n;
        return delete_bst_node(root, successor);
    }
}

/**
 * Removes a node from a binary search tree recursively.
 */
bst_t *remove_bst_node_recursive(bst_t *root, bst_t *node, int value) {
    if (node != NULL) {
        if (node->n == value) {
            return delete_bst_node(root, node);
        } else if (node->n > value) {
            return remove_bst_node_recursive(root, node->left, value);
        } else {
            return remove_bst_node_recursive(root, node->right, value);
        }
    }
    return NULL;
}

/**
 * Removes a node from a binary search tree.
 */
bst_t *bst_remove(bst_t *root, int value) {
    return remove_bst_node_recursive(root, root, value);
}

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void) {
    bst_t *tree;
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22, 98, 1, 62, 95
    };
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = array_to_bst(array, n);
    if (!tree) {
        return (1);
    }
    binary_tree_print(tree);

    tree = bst_remove(tree, 79);
    printf("Removed 79...\n");
    binary_tree_print(tree);

    tree = bst_remove(tree, 21);
    printf("Removed 21...\n");
    binary_tree_print(tree);

    tree = bst_remove(tree, 68);
    printf("Removed 68...\n");
    binary_tree_print(tree);

    binary_tree_delete(tree);
    return (0);
}

