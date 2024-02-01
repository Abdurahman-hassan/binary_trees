#include "binary_trees.h"

/**
 * update_balance - Updates the balance of the AVL tree and performs rotations
 * @tree: Double pointer to the root node of the AVL tree
 * @node: Pointer to the current node
 * Return: Pointer to the balanced node
 */
avl_t *update_a_balance(avl_t **tree, avl_t *node)
{
	int balance;
	int balance_child;

	balance = binary_tree_balance(node);

	if (balance > 1)
	{
		balance_child = binary_tree_balance(node->left);
		if (balance_child < 0)
			node->left = binary_tree_rotate_left(node->left);

		node = binary_tree_rotate_right(node);
	} else if (balance < -1)
	{
		balance_child = binary_tree_balance(node->right);
		if (balance_child > 0)
			node->right = binary_tree_rotate_right(node->right);

		node = binary_tree_rotate_left(node);
	}

	/* Update the tree root if the current node */
	/* has become the root of the entire tree */
	if (node->parent == NULL && *tree != node)
		*tree = node;

	return (node);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree for removing a node
 * @value: Value to remove in the tree
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
			temp = root->left ? root->left : root->right;
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
	root = update_a_balance(&root, root);
	return (root);
}
