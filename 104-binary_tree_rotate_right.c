#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *left_child;

	/* Check if tree is NULL */
	if (tree == NULL)
		return (NULL);
	/* Check if tree has a left child */
	if (tree->left == NULL)
		return (tree);
	/* Rotate tree */
	left_child = tree->left->right, tree->left->right = tree;
	tree->left->parent = NULL, tree->parent = tree->left;
	tree->left = left_child;
	if (left_child != NULL)
		left_child->parent = tree;  /* Update the parent of left_child */
	return (tree->parent);
}
