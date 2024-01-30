#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Create a node in binary tree
 *
 * @parent: Pointer to the parent node
 * @value: Value of this node
 *
 * Return: Pointer to the created node
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);
	node->parent = parent, node->n = value, node->left = node->right = NULL;
	return (node);
}
