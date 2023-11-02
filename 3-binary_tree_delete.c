#include "binary_trees.h"
#include <stdlib.h>

void delete_binary_tree(binary_tree_t *node)
{
    if (node == NULL)
        return;

    delete_binary_tree(node->left);
    delete_binary_tree(node->right);
    free(node);
}

void binary_tree_delete(binary_tree_t *tree)
{
    if (tree == NULL)
        return;

    delete_binary_tree(tree);
}
