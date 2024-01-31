#include "binary_trees.h"
#include <limits.h>

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
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root of the tree or subtree
 * Return: Balance factor of the tree or subtree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int diff;

	/* If tree is NULL, return 0 */
	if (tree == NULL)
		return (1);
	diff = binary_tree_height(tree->left) - binary_tree_height(tree->right);
	if (diff > 1 || diff < -1)
		return (0);

	/* Return the difference between the left and right subtrees */
	return (binary_tree_balance(tree->left) && binary_tree_balance(tree->right));
}

/**
 * binary_tree_is_bst2 - Checks if a binary search tree is a valid
 * @tree: pointer to the root node of the tree or subtree
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst2(const binary_tree_t *tree, int mn, int mx)
{
	/* if tree is NULL, return 1 */
	if (tree == NULL)
		return (1);
	if (tree->left && tree->n <= tree->left->n)
		return (0);
	if (tree->right && tree->n >= tree->right->n)
		return (0);
	if (tree->n < mn || tree->n > mx)
		return (0);
	
	return (binary_tree_is_bst2(tree->left, mn, tree->n - 1) &&
	binary_tree_is_bst2(tree->right, tree->n + 1, mx));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid avl tree
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	/* if tree is complete and valid binary search tree then it's valid avl */
	return (binary_tree_is_bst2(tree, INT_MIN, INT_MAX) && binary_tree_balance(tree));
}
