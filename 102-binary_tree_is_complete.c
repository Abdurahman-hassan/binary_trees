#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree, or 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	/* recursively call the function */
	/* to get the size of the left and right subtrees */
	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 * is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @index: index of the node
 * @nodes: number of nodes in the tree
 * Return: 1 if tree is complete, 0 otherwise
 */

int is_complete(const binary_tree_t *tree, int index, int nodes)
{
	/* if tree is NULL, it is complete */
	if (!tree)
		return (1);

	/* if index assigned to current node is more than number of nodes */
	/* in tree, then tree is not complete */
	if (index >= nodes)
		return (0);

	/* recursively check the left and right subtrees */
	return (is_complete(tree->left, 2 * index + 1, nodes) &&
			is_complete(tree->right, 2 * index + 2, nodes));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int nodes, index = 0;

	/* if tree is NULL, it is not complete */
	if (!tree)
		return (0);

	/* get the number of nodes in the tree */
	nodes = binary_tree_size(tree);

	/* check if the tree is complete */
	return (is_complete(tree, index, nodes));
}

