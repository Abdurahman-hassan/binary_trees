#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array
 *
 * @tree: Pointer to the first element of the array to be converted
 * @size: Number of element in the array
 *
 * Return: Pointer to the root node of the created Binary Heap, or NULL on fail
 */

heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
    size_t i = 0;

    for (; i < size; ++i)
        heap_insert(&root, array[i]);
    return (root);
}
