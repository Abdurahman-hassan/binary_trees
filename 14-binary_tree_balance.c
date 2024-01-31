#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root of the tree or subtree
 * This function recursively traverses the tree,
 * subtracting the height of the
 * right subtree from the height of the left
 * subtree at each node to calculate the balance factor.
 * Return: Balance factor of the tree or subtree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	/* If tree is NULL, return 0 */
	if (!tree)
		return (0);

	/* Recursively measure the height of the left subtree */
	if (tree->left)
		left_height = 1 + binary_tree_balance(tree->left);

	/* Recursively measure the height of the right subtree */
	if (tree->right)
		right_height = 1 + binary_tree_balance(tree->right);

	/* Return the difference between the heights of the left and right subtrees */
	return (left_height - right_height);
}
