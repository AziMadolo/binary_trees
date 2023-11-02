#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * queue_push - Pushes a binary tree node to the queue.
 * @node: A pointer to the binary tree node to push.
 * @tail: A double pointer to the tail of the queue.
 *
 * Return: A pointer to the newly created queue node.
 */
queue_node_t *queue_push(binary_tree_t *node, queue_node_t **tail)
{
    queue_node_t *new_node = malloc(sizeof(queue_node_t));
    if (new_node == NULL)
        exit(1);

    new_node->node = node;
    new_node->next = NULL;

    if (*tail == NULL)
    {
        *tail = new_node;
    }
    else
    {
        (*tail)->next = new_node;
        *tail = new_node;
    }

    return new_node;
}

/**
 * queue_pop - Pops a node from the queue.
 * @head: A double pointer to the head of the queue.
 */
void queue_pop(queue_node_t **head)
{
    queue_node_t *tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    queue_node_t *head = NULL;
    queue_node_t *tail = NULL;

    queue_push((binary_tree_t *)tree, &tail);

    while (head != NULL)
    {
        binary_tree_t *current = head->node;
        func(current->n);

        if (current->left != NULL)
            queue_push(current->left, &tail);
        if (current->right != NULL)
            queue_push(current->right, &tail);

        queue_pop(&head);
    }
}

