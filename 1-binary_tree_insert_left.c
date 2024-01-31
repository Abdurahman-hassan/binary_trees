#include "binary_trees.h"

/**
 * binary_tree_insert_left - Create a node in a binary tree as a left child
 * @parent: Pointer to the parent node
 * @value: Value of the created node
 * Return: Pointer to the created node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	/* create a new node */
	binary_tree_t *new_left_child;

	/* check if malloc failed */
	if (parent == NULL)
		return (NULL);

	/* initialize the new node */
	new_left_child = binary_tree_node(parent, value);

	/* check if malloc failed */
	if (new_left_child == NULL)
		return (NULL);

	/* update the parent's left child */
	if (parent->left != NULL)
	{
		/* update the new node's left child */
		new_left_child->left = parent->left;
		parent->left->parent = new_left_child;
	}

	/* update the parent's left child */
	parent->left = new_left_child;
	return (new_left_child);
}
