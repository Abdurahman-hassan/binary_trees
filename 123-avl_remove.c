#include "binary_trees.h"

/**
 * balance_factor - Measures the balance factor of an AVL tree and performs
 * rotations if necessary to maintain balance.
 *
 * @tree: The AVL tree to calculate the balance factor for and balance.
 */
void balance_factor(avl_t **tree)
{
	int bfactor;

	/* Check if the tree is empty or a leaf node */
	if (tree == NULL || *tree == NULL)
		return;

	/* If the node has no children, it's already balanced */
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	/* Recursively calculate balance factors for left and right subtrees */
	balance_factor(&(*tree)->left);
	balance_factor(&(*tree)->right);

	/* Calculate the balance factor of the current node */
	bfactor = binary_tree_balance((const binary_tree_t *)*tree);

	/* Perform rotations to balance the tree */
	if (bfactor > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bfactor < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * get_successor - Get the next successor (minimum node) in the right subtree.
 *
 * @node: The node to check for a successor.
 *
 * Return: The minimum value in the tree.
 */
int get_successor(bst_t *node)
{
	int left = 0;

	/* Check if the node is NULL */
	if (node == NULL)
	{
		return (0);
	}
	else
	{
		/* Recursively find the leftmost node for successor */
		left = get_successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}

/**
 * remove_node_type - Function that removes a node depending on its children.
 *
 * @root: The node to remove.
 *
 * Return: 0 if it has no children, or another value if it has.
 */
int remove_node_type(bst_t *root)
{
	int new_value = 0;

	/* Check if the node has no children */
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		/* Node has two children, find the successor, update the value */
		new_value = get_successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove_node - Remove a node from a BST tree.
 * @root: The root of the BST tree.
 * @value: The value of the node to remove.
 *
 * Return: The updated tree.
 */
bst_t *bst_remove_node(bst_t *root, int value)
{
	int type = 0;

	/* Check if the tree is empty */
	if (root == NULL)
		return (NULL);

	/* Search for the node with the specified value */
	if (value < root->n)
		bst_remove_node(root->left, value);
	else if (value > root->n)
		bst_remove_node(root->right, value);
	else if (value == root->n)
	{
		/* Remove the node and its value depending on the number of children */
		type = remove_node_type(root);
		if (type != 0)
			bst_remove_node(root->right, type);
	}
	else
		return (NULL);

	return (root);
}

/**
 * avl_remove - Remove a node from an AVL tree.
 *
 * @root: The root of the AVL tree.
 * @value: The value of the node to remove.
 *
 * Return: The updated AVL tree.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove_node((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);

	/* Balance the AVL tree after removing a node */
	balance_factor(&root_a);
	return (root_a);
}
