#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_node - function that creates a binary tree node.
 *
 * @parent: pointer to the parent node of the node to create
 * @value:  value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* creates the new node */
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = value;
	/* append the new node to the parent */
	new_node->parent = parent;

	/* returns the new node */
	return (new_node);
}
