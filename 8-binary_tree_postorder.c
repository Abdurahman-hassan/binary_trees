#include "binary_trees.h"

/**
 * binary_tree_postorder - print tree elements in the order (left, right, root)
 *
 * @tree: Pointer to the root of the tree or subtree
 * @func: Pointer to a function
 *
 * Return: Nothing
*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	/* if tree or func is NULL, do nothing */
	if (tree == NULL || func == NULL)
		return;

	/* traverse left subtree */
	binary_tree_postorder(tree->left, func);
	/* traverse right subtree */
	binary_tree_postorder(tree->right, func);
	/* call func on current node */
	func(tree->n);
}
