#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 *
 * Return: pointer to the node containing a value equals to value
 *         NULL if tree is NULL or if nothing is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	/* if the value is found */
	if (tree->n == value)
		/* return the node */
		return ((bst_t *)tree);

	/* if the value is less than the current node */
	if (tree->n > value)
		/* search the left subtree and return the result */
		return (bst_search(tree->left, value));
	/* if the value is greater than the current node */
	/* search the right subtree and return the result */
	return (bst_search(tree->right, value));
}
