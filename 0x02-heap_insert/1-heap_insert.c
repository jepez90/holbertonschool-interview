#include "binary_trees.h"
#include <stdio.h>

/**
 * heap_insert - inserts a value into a Max Binary Heap
 *
 * @root: pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int left, right;
	heap_t *new_node;

	if (*root == NULL)
	{
		new_node = binary_tree_node(*root, value);
		*root = new_node;
		return (new_node);
	}
	else
	{
		left = binary_tree_length((*root)->left);
		right = binary_tree_length((*root)->right);

		if (right < left)
			return (_heap_insert((*root)->right, value));
		else
			return (_heap_insert((*root)->left, value));
	}
}

/**
 * _heap_insert - recursive function
 *
 * @root: pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: new node
 */
heap_t *_heap_insert(heap_t *root, int value)
{
	int left, right;

	left = binary_tree_length(root->left);
	right = binary_tree_length(root->right);

	if (right < left)

		return (_heap_insert(root->right, value));

	else
		return (_heap_insert(root->left, value));
}

/**
 * binary_tree_length - calculates the less lengt of the tree
 *
 * @root: pointer to root of the tree
 * Return: less length of the tree
 */
int binary_tree_length(heap_t *root)
{
	int left, right;

	if (root == NULL)
		return (0);

	right = binary_tree_length(root->right);
	left = binary_tree_length(root->left);

	if (right < left)
		return (right);
	else
		return (left);
}
