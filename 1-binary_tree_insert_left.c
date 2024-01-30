#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - Create a node in a binary tree as a left child
 *
 * @parent: Pointer to the parent node
 * @value: Value of the created node
 *
 * Return: Pointer to the created node
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (parent == NULL)
		return (NULL);
	binary_tree_t *old_left_child = parent->left;
	binary_tree_t *new_left_child = binary_tree_node(parent, value);
	if (new_left_child == NULL)
		return (NULL);
	new_left_child->left = old_left_child;
	parent->left = new_left_child;
	return (new_left_child);
}
