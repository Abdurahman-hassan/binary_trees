#include "binary_trees.h"

/**
 * avl_search - Searches for a value in an AVL tree
 * @tree: Pointer to the root node of the AVL tree
 * @value: The value to search for
 *
 * Return: 1 if value exists in the tree, 0 otherwise
 */
int avl_search(avl_t *tree, int value)
{
	if (!tree)
		return (0);

	if (value < tree->n)
		return (avl_search(tree->left, value));
	else if (value > tree->n)
		return (avl_search(tree->right, value));
	else
		return (1);
}

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		/* Insert only if the value is not already present in the tree */
		if (!avl_search(tree, array[i]))
			avl_insert(&tree, array[i]);
	}

	return (tree);
}
