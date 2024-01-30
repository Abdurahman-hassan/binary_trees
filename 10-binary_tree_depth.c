#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 *
 * @tree: Pointer to the node to measure the depth
 *
 * Return: the depth of the node
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t the_depth = 0;
	binary_tree_t *node = tree;
	if (!tree)
		return (0);
	while (node->parent)
		++the_depth, node = node->parent;
	return (the_depth);
}
