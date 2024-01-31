#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checking whether a binary tree is perfect or not
 *
 * @tree: Pointer to the root in tree or subtree
 *
 * Return: 1 if tree is prefect otherwise 0
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t tree_size, tree_height;

	if (!tree)
		return (0);
	tree_size = binary_tree_size(tree), tree_height = binary_tree_height(tree);
	if ((tree_size + 1) == ((size_t) 1 << (tree_height + 1)))
		return (1);
	return (0);
}
