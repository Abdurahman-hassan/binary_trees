#include "binary_trees.h"

/**
 * binary_tree_is_leaf2 - Checks if a node is a leaf or not
 * @node: Pointer to the node to check
 * A node is considered a leaf
 * if it has no children (i.e., both its left and right pointers are NULL).
 * Return: 1 if the node is a leaf, otherwise 0
 */
int binary_tree_is_leaf2(const binary_tree_t *node)
{
	/* If node is NULL or has a left or right child, it is not a leaf */
	if (node == NULL || node->left || node->right)
		return (0);
	return (1);
}

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root of the tree or subtree
 * This function recursively traverses the tree,
 * incrementing a counter each time it encounters a leaf node.
 * Return: Number of leaves in the tree or subtree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t is_leaf = 0;

	/* If tree is NULL, return 0 */
	/* If tree has no children, return 1 */
	if (!tree)
		return (is_leaf);

	/* Recursively count the leaves in the left and right subtrees */
	is_leaf += binary_tree_leaves(tree->left);
	is_leaf += binary_tree_leaves(tree->right);
	/* If the current node is a leaf, increment the counter */
	is_leaf += (size_t) binary_tree_is_leaf2(tree);
	return (is_leaf);
}
