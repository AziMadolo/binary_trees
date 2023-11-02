#include "binary_trees.h"

/**
 * balance - Measures the balance factor of an AVL tree
 * @tree: AVL tree to balance
 * Return: Balance factor
 */
void balance(avl_t **tree)
{
    /* Same implementation as before */
}

/**
 * get_successor - Get the next successor, i.e., the minimum node in the right subtree
 * @node: Node to check
 * Return: The minimum value of the subtree rooted at the given node
 */
int get_successor(bst_t *node)
{
    /* Same implementation as before */
}

/**
 * remove_node_type - Function that removes a node depending on its children
 * @root: Node to remove
 * Return: 0 if it has no children, or other value if it has
 */
int remove_node_type(bst_t *root)
{
    /* Same implementation as before */
}

/**
 * bst_remove - Remove a node from a BST tree
 * @root: Root of the tree
 * @value: Node with this value to remove
 * Return: The updated tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
    /* Same implementation as before */
}

/**
 * avl_remove - Remove a node from an AVL tree
 * @root: Root of the tree
 * @value: Node with this value to remove
 * Return: The updated tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
    /* Same implementation as before */
}

int main(void)
{
    avl_t *tree;
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22, 98, 1, 62, 95
    };
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = array_to_avl(array, n);
    if (!tree)
        return (1);
    binary_tree_print(tree);

    tree = avl_remove(tree, 47);
    printf("Removed 47...\n");
    binary_tree_print(tree);

    tree = avl_remove(tree, 79);
    printf("Removed 79...\n");
    binary_tree_print(tree);

    tree = avl_remove(tree, 32);
    printf("Removed 32...\n");
    binary_tree_print(tree);

    tree = avl_remove(tree, 34);
    printf("Removed 34...\n");
    binary_tree_print(tree);

    tree = avl_remove(tree, 22);
    printf("Removed 22...\n");
    binary_tree_print(tree);

    binary_tree_delete(tree);
    return (0);
}

