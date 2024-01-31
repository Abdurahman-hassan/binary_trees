#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root of the tree or subtree
 * Return: Height of the tree or subtree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (-1);

	left_height = 1 + binary_tree_height(tree->left);
	right_height = 1 + binary_tree_height(tree->right);

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root of the tree or subtree
 *
 * Return: Size of the tree or subtree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks whether a binary tree is perfect or not
 * @tree: Pointer to the root of the tree or subtree
 * A binary tree is perfect if all its levels are completely filled.
 * This function calculates the size and height of the tree,
 * and checks if the size is equal to 2^(height+1) - 1.
 * Return: 1 if the tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t tree_size, tree_height;

	/* If tree is NULL, return 0 */
	if (!tree)
		return (0);

	/* Calculate the size and height of the tree */
	tree_size = binary_tree_size(tree);
	tree_height = binary_tree_height(tree);

	/* Check if the size is equal to 2^(height+1) - 1 */
	if ((tree_size + 1) == ((size_t) 1 << (tree_height + 1)))
		return (1);

	/* If the size is not equal to 2^(height+1) - 1, the tree is not perfect */
	return (0);
}
