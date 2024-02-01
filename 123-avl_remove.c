#include "binary_trees.h"

avl_t *update_balance(avl_t **tree, avl_t *node);

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
	avl_t *temp = NULL;

	if (root == NULL)
		return (root);
	/* Perform standard BST delete */
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		/* Node with only one child or no child */
		if ((root->left == NULL) || (root->right == NULL))
		{
			avl_t *temp = root->left ? root->left : root->right;
			/* No child case */
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
				/* One child case */
				*root = *temp; /* Copy the contents of the non-empty child */
			free(temp);
		} else
		{
			temp = root->right; /* node with two children: Get inorder successor */
			while (temp->left != NULL)
				temp = temp->left;
			root->n = temp->n; /* Copy inorder successor's data to this node */
			root->right = avl_remove(root->right, temp->n); /* Delete inorder succesor*/
		}
	}
	/* If the tree had only one node, then return */
	if (root == NULL)
		return (root);
	/* Update the balance factor of the node and balance the tree */
	root = update_balance(&root, root);
	return (root);
}
