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
	avl_t *child = NULL;
	int md = (mn + mx) / 2;

	if (mn > mx)
		return;
	child = binary_tree_node(parent_to_child, arr[md]);
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
	md = (size - 1) / 2;
	tree = binary_tree_node(NULL, array[md]);
	add_to_tree(array, tree, (int) md + 1, (int) size - 1, 'R');
	add_to_tree(array, tree, 0, (int) md - 1, 'L');
	return (tree);
}
