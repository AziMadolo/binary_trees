#include "binary_trees.h"

/**
 * find_lowest_common_ancestor - Finds the lowest common ancestor of two nodes.
 * @node1: Pointer to the first node.
 * @node2: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *find_lowest_common_ancestor(const binary_tree_t *node1,
                                            const binary_tree_t *node2)
{
    binary_tree_t *parent_node1, *parent_node2;

    if (!node1 || !node2)
        return NULL;

    if (node1 == node2)
        return ((binary_tree_t *)node1);

    parent_node1 = node1->parent;
    parent_node2 = node2->parent;

    if (node1 == parent_node2 || !parent_node1 || (!parent_node1->parent && parent_node2))
        return find_lowest_common_ancestor(node1, parent_node2);
    else if (parent_node1 == node2 || !parent_node2 || (!parent_node2->parent && parent_node1))
        return find_lowest_common_ancestor(parent_node1, node2);
    
    return find_lowest_common_ancestor(parent_node1, parent_node2);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                      const binary_tree_t *second)
{
    return find_lowest_common_ancestor(first, second);
}

