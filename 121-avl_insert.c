#include "binary_trees.h"

avl_t *insert_avl_node(avl_t **tree, avl_t *node, int value);
avl_t *update_balance(avl_t **tree, avl_t *node);

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: The value to insert
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *inserted_node = NULL;

	if (!tree)
		return (NULL);

	/* Insert the value and get back the inserted node */
	inserted_node = insert_avl_node(tree, *tree, value);

	/* If the tree root was NULL, the inserted node is the new root */
	if (!*tree)
		*tree = inserted_node;

	/* Return the inserted node */
	return (inserted_node);
}


/**
 * insert_avl_node - Helper function to insert a node in AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @node: Pointer to the current node
 * @value: The value to insert
 * Return: Pointer to the inserted node
 */
avl_t *insert_avl_node(avl_t **tree, avl_t *node, int value)
{
	avl_t *new_node = NULL;

	if (node == NULL)
	{
		node = binary_tree_node(NULL, value);
		if (*tree == NULL)
			*tree = node;
		return (node);
	}

	if (value < node->n)
	{
		new_node = insert_avl_node(tree, node->left, value);
		if (node->left == NULL)
		{
			node->left = new_node;
			new_node->parent = node;
		}
	} else if (value > node->n)
	{
		new_node = insert_avl_node(tree, node->right, value);
		if (node->right == NULL)
		{
			node->right = new_node;
			new_node->parent = node;
		}
	}
	/* Update the balance factors and perform necessary rotations */
	update_balance(tree, node);

	return (new_node ? new_node : node);
}

/**
 * update_balance - Updates the balance of the AVL tree and performs rotations
 * @tree: Double pointer to the root node of the AVL tree
 * @node: Pointer to the current node
 * Return: Pointer to the balanced node
 */
avl_t *update_balance(avl_t **tree, avl_t *node)
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
