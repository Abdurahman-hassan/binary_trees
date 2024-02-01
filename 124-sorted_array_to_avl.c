#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 * @arr: Pointer to the first element of the array to be converted
 * @parent_to_child: Pointer to parent
 * @mn: Maximum number index can be
 * @mx: Minimum number index can be
 * @flag: L if the child is left otherwise R
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */

void add_to_tree(int *arr, avl_t *parent_to_child, int mn, int mx, char flag)
{
	int md = (mn + mx) / 2;
	avl_t *child;

	if (mn > mx)
		return;
	child = malloc(sizeof(avl_t));
	if (child == NULL)
		return;
	child->n = arr[md], child->parent = parent_to_child;
	child->left = child->right = NULL;
	if (flag == 'L')
		parent_to_child->left = child;
	else
		parent_to_child->right = child;
	add_to_tree(arr, child, md + 1, mx, 'R');
	add_to_tree(arr, child, mn, md - 1, 'L');
}

/**
 * array_to_avl - Builds an AVL tree from an array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of element in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t md;

	if (array == NULL || size == 0)
		return (NULL);
	tree = malloc(sizeof(avl_t));
	if (tree == NULL)
		return (NULL);
	tree->parent = tree->left = tree->right = NULL;
	md = (size - 1) / 2, tree->n = array[md];
	add_to_tree(array, tree, (int) md + 1, (int) size - 1, 'R');
	add_to_tree(array, tree, 0, (int) md - 1, 'L');
	return (tree);
}
