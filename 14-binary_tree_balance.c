#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: Pointer to the root in tree or subtree
 *
 * Return: Balance factor
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	int node_balance = 0;
	if (!tree)
		return (0);
	node_balance = binary_tree_height(tree->left) - binary_tree_height(tree->right);
	return (node_balance);
}
