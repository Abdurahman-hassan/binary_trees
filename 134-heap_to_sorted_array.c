#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree, or 0 if tree is NULL
 */

size_t binary_tree_size2(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	/* recursively call the function */
	/* to get the size of the left and right subtrees */
	return (binary_tree_size2(tree->left) + 1 + binary_tree_size2(tree->right));
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of int
 *
 * @heap: Pointer to the root node of the heap to convert
 * @size: Number of element in the array
 *
 * Return: Pointer to the sorted array
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *arr = malloc(sizeof(int) * binary_tree_size2(heap));
	size_t i = 0;

	if (arr == NULL || heap == NULL || size == NULL)
		return (NULL);
	*size = binary_tree_size2(heap);
	for (i = 0; i < *size; ++i)
		arr[i] = heap_extract(&heap);
	return (arr);
}
