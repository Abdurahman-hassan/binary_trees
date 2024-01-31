# include "binary_trees.h"

/**
 * binary_tree_height - measure the height of a binary tree
 * @tree: Pointer to the root of the tree or subtree
 * Return: Height of the tree or subtree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	/* if tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/* if tree has no children, return 0 */
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	/* traverse left subtree */
	left_height = binary_tree_height(tree->left);
	/* traverse right subtree */
	right_height = binary_tree_height(tree->right);

	/* return the greater of the two heights */
	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}
