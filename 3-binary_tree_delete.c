#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_delete - delete all binary tree
 *
 * @tree: Pointer to the parent node
 *
 * Return: NULL
*/

void binary_tree_delete(binary_tree_t *tree)
{
    if (tree == NULL)
        return (NULL);
    binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
    free(tree);
}
