#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 *
 * @tree: Pointer to the root in tree or subtree
 * @func: Pointer to a function usually just print value
 *
 * Return: Nothing
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    size_t last = 1, first = 0, tree_sz = binary_tree_size(tree), i = 0;
    binary_tree_t *arr;
	if (tree == NULL || func == NULL)
		return;
    arr = malloc(sizeof(binary_tree_t) * tree_sz);
    if (arr == NULL)
        return;
    arr[0] = *tree;
    while (last < tree_sz)
    {
        if (arr[first].left)
            arr[last++] = *(arr[first].left);
        if (arr[first].right)
            arr[last++] = *(arr[first].right);
        ++first;
    }
    for (; i < tree_sz; ++i)
        func(arr[0].n);
    free(arr);
}
