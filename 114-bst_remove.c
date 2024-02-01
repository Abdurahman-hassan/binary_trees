#include "binary_trees.h"

/**
 * zero_child - Removes a node that has zero child
 * @node: Pointer to the node to be removed
 * @value: The value to remove in the tree
 * Return: Nothing
*/
void zero_child(bst_t *node, int value)
{
	/* if the node is the root */
	if (node->parent != NULL)
	{
		/* if the node is the left child of its parent */
		/* set the left child of the parent to NULL */
		if (node->parent->left->n == value)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
	}
	free(node);
	node = NULL;
}

/**
 * one_child - Removes a node that has one child
 * @node: Pointer to the node to be removed
 * @value: The value to remove in the tree
 * Return: Nothing
*/

void one_child(bst_t *node, int value)
{
	bst_t *child = NULL;

	if (node->left)
		child = node->left, child->parent = node->parent;
	else
		child = node->right, child->parent = node->parent;
	if (node->parent != NULL)
	{
		if (node->parent->left && node->parent->left->n == value)
			node->parent->left = child;
		else
			node->parent->right = child;
	}
	free(node);
	node = NULL;
}

/**
 * find_successor - Find first in-order successor to the node to be removed
 *
 * @node: Pointer to the node to be removed
 *
 * Return: Pointer to the new root node of the tree
*/

bst_t *find_successor(bst_t *node)
{
	node = node->right;
	while (node->left)
		node = node->left;
	return (node);
}

/**
 * two_child - Removes a node that has two child
 *
 * @node: Pointer to the node to be removed
 * @value: The value to remove in the tree
 *
 * Return: Nothing
*/

void two_child(bst_t *node, int value)
{
	/* find the first in-order successor */
	bst_t *successor = find_successor(node);
	/* swap the value of the node to be removed with the successor */
	node->n = successor->n;
	successor->n = value;
	/* remove the successor */
	if (successor->left || successor->right)
		one_child(successor, value);
	else
		zero_child(successor, value);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 *
 * @root: Pointer to the root of the tree or subtree
 * @value: The value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree
*/

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = root;

	if (root == NULL)
		return (NULL);
	while (node)
	{
		if (node->n < value)
			node = node->right;
		else if (node->n > value)
			node = node->left;
		else
			break;
	}
	if (node == NULL)
		return (root);
	if (node->left && node->right)
		two_child(node, value);
	else if (!(node->left) && !(node->right))
		zero_child(node, value);
	else
		one_child(node, value);
	return (root);
}
