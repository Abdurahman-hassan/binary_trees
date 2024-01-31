#include "binary_trees.h"

/**
 * binary_tree_delete - delete all binary tree
 * @tree: Pointer to the parent node
 * Return: NULL
*/
void binary_tree_delete(binary_tree_t *tree)
{
	/* check if tree is NULL */
	if (tree == NULL)
		return;

	/* delete the left and right subtrees */
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

    /* delete the current node */
	free(tree);
}
