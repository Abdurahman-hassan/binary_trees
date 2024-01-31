#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child
 * in a binary tree
 * @tree: Pointer to the root node of the tree
 * to count the number of nodes
 * This function recursively traverses the tree,
 * incrementing a counter each time it
 * encounters a node with at least one child.
 * Return: Number of nodes with at least 1 child in a binary tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	/* If tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/* If tree has at least 1 child, increment nodes */
	if (tree->left != NULL || tree->right != NULL)
		nodes++;

	/* Recursively call binary_tree_nodes() on left and right subtrees */
	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);

	return (nodes);
}
