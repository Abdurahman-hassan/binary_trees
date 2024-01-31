#include "binary_trees.h"

/**
 * binary_tree_preorder - print tree elements in the order (root, left, right)
 * @tree: Pointer to the root of the tree or subtree
 * @func: Pointer to a function
 * Return: Nothing
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	/* check if tree or func is NULL */
	if (tree == NULL || func == NULL)
		return;

	/* print the root */
	func(tree->n);

	/* traverse the left subtree */
	binary_tree_preorder(tree->left, func);

	/* traverse the right subtree */
	binary_tree_preorder(tree->right, func);
}
