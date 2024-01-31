#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 * Return: the depth of the node
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t the_depth = 0;

	/* if tree is NULL, return 0 */
	if (!tree)
		return (0);

	/* traverse up the tree, counting the depth */
	while (tree->parent)
		/* increment depth and move up the tree */
		++the_depth, tree = tree->parent;

	/* return the depth */
	return (the_depth);
}
