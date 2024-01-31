# include "binary_trees.h"

/**
 * binary_tree_size - measure the size of a binary tree
 * @tree: Pointer to the root of the tree or subtree
 * Return: Size of the tree or subtree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size = 0;
	size_t right_size = 0;

	/* if tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/* if tree has no children, return 1 */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* traverse left subtree */
	left_size = binary_tree_size(tree->left);
	/* traverse right subtree */
	right_size = binary_tree_size(tree->right);

	/* return the sum of the sizes of the subtrees */
	return (left_size + right_size + 1);
}
