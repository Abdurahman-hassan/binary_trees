# include "binary_trees.h"

/**
 * binary_tree_is_root - Checking whether the node is root or not
 * @node: Pointer to node
 * Return: 1 if node is a root, otherwise 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	/* check if node is NULL */
	/* check if node has parent */
	/* if node is NULL or has parent, return 0 */
	/* otherwise, return 1 */
	if (node == NULL || node->parent)
		return (0);
	return (1);
}
