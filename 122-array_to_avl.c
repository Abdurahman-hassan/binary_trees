#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 *
 * @tree: Pointer to the first element of the array to be converted
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */

avl_t *array_to_avl(int *array, size_t size)
{
	bst_t *root = NULL;
    size_t i = 0;

    for (; i < size; ++i)
        avl_insert(&root, array[i]);
    return (root);
}
