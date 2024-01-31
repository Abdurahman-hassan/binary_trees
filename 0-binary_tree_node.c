#include "binary_trees.h"

/**
 * binary_tree_node - Create a node in binary tree
 * @parent: Pointer to the parent node
 * @value: Value of this node
 * Return: Pointer to the created node
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	/* create a new node */
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	/* check if malloc failed */
	if (node == NULL)
		return (NULL);

    /* initialize the new node */
	node->parent = parent, node->n = value, node->left = node->right = NULL;
	return (node);
}
