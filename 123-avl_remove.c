#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree
 *
 * @root: Pointer to the root node of the tree for removing a node
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing the value
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node = NULL;

	if (!root)
		return (NULL);

	if (root->n == value)
	{
		if (!root->left && !root->right)
		{
			free(root);
			return (NULL);
		}
		else if (!root->left || !root->right)
		{
			node = root->left ? root->left : root->right;
			free(root);
			return (node);
		}
		else
		{
			node = root->right;
			while (node->left)
				node = node->left;
			root->n = node->n;
			root->right = avl_remove(root->right, node->n);
		}
	}
	else if (root->n > value)
		root->left = avl_remove(root->left, value);
	else
		root->right = avl_remove(root->right, value);

	return (root);
}
