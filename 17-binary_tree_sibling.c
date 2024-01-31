#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: pointer to the sibling node, or NULL if no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	/* if node is NULL or has no parent, return NULL */
	if (!node || !node->parent)
		return (NULL);

	/* find the parent of the node */
	parent = node->parent;

	/* if node is the left child, return the right child */
	if (parent->left == node)
		return (parent->right);

	/* if node is the right child, return the left child */
	return (parent->left);
}

