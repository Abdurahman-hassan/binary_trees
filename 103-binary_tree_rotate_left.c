#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node of the tree once rotated
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *right_child;

	/* Check if tree is NULL */
	if (tree == NULL)
		return (NULL);
	/* Check if tree has a right child */
	if (tree->right == NULL)
		return (tree);
	/* Rotate tree */
	right_child = tree->right->left, tree->right->left = tree;
	tree->right->parent = NULL, tree->parent = tree->right;
	tree->right = right_child;
	return (tree->parent);
}
