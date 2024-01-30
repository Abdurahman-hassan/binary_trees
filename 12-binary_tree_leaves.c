#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 *
 * @tree: Pointer to the root in tree or subtree
 *
 * Return: Number of leaves
*/

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t is_leaf = 0;
	if (!tree)
		return (is_leaf);
	is_leaf += binary_tree_leaves(tree->left);
	is_leaf += binary_tree_leaves(tree->right);
	is_leaf += (size_t) binary_tree_is_leaf(tree);
	return (is_leaf);
}
