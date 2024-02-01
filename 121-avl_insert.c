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
	if (tree == NULL)
		return (NULL);

	return (insert_avl_node(tree, *tree, value));
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
	if (node == NULL)
	{
		/* Create a new node */
		node = binary_tree_node(NULL, value);
		if (*tree == NULL)
			*tree = node;
		return (node);
	}

	/* Insert the node as in a binary search tree */
	if (value < node->n)
	{
		/* Insert in the left subtree */
		avl_t *left_child = insert_avl_node(tree, node->left, value);

		if (node->left == NULL)
		{
			node->left = left_child;
			left_child->parent = node;
		}
	} else if (value > node->n)
	{
		/* Insert in the right subtree */
		avl_t *right_child = insert_avl_node(tree, node->right, value);

		if (node->right == NULL)
		{
			node->right = right_child;
			right_child->parent = node;
		}
	}
	else
		/* Duplicate values are not allowed in AVL tree */
		return (NULL);

	/* Update balance and perform rotations */
	return (update_balance(tree, node));
}

/**
 * update_balance - Updates the balance of the AVL tree and performs rotations
 * @tree: Double pointer to the root node of the AVL tree
 * @node: Pointer to the current node
 * Return: Pointer to the balanced node
 */
avl_t *update_balance(avl_t **tree, avl_t *node)
{
	int balance = binary_tree_balance(node);

	/* Left heavy situation */
	if (balance > 1)
	{
		if (binary_tree_balance(node->left) < 0)
		{
			node->left = binary_tree_rotate_left(node->left);
		}
		node = binary_tree_rotate_right(node);
	}
	/* Right heavy situation */
	else if (balance < -1)
	{
		if (binary_tree_balance(node->right) > 0)
		{
			node->right = binary_tree_rotate_right(node->right);
		}
		node = binary_tree_rotate_left(node);
	}

	/* Correctly setting the new root of the subtree if rotations were made */
	if (!node->parent)
	{
		*tree = node; /* Update the root of the tree */
	}

	return (node);
}
