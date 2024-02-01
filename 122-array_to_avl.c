#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i = 0, j = 0, last = 0;
	int arr[size];

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; ++i)
	{
		arr[i] = array[i];
	}

	for (i = 0; i < size; ++i)
	{
		int flag = 1;

		for (j = 0; j < i; ++j)
		{
			if (arr[i] == arr[j])
				flag = 0;
		}
		if (flag)
			arr[last++] = arr[i];
	}
	for (i = 0; i < last; ++i)
		if (avl_insert(&root, arr[i]) == NULL)
			return (NULL);
	return (root);
}
