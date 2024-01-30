#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - Create a node in a binary tree as a right child
 *
 * @parent: Pointer to the parent node
 * @value: Value of the created node
 *
 * Return: Pointer to the created node
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *old_right_child, *new_right_child;
	if (parent == NULL)
		return (NULL);
	old_right_child = parent->right;
	new_right_child = binary_tree_node(parent, value);
	if (new_right_child == NULL)
		return (NULL);
	new_right_child->right = old_right_child;
	parent->right = new_right_child;
	return (new_right_child);
}
