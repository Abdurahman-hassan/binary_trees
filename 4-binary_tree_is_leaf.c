#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checking whether the node is leaf or not
 *
 * @node: Pointer to node
 *
 * Return: 1 if node is a leaf, otherwise 0
*/

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left || node->right)
		return (0);
	return (1);
}
