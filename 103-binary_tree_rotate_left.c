#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
*/

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *right_child;

	if (tree == NULL)
		return (NULL);
	if (tree->right == NULL)
		return (tree);
	right_child = tree->right->left, tree->right->left = tree;
	tree->right->parent = NULL, tree->parent = tree->right;
	tree->right = right_child;
	return (tree->parent);
}
