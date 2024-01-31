#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_size - measure the size of a binary tree
 * @tree: Pointer to the root of the tree or subtree
 * Return: Size of the tree or subtree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size = 0;
	size_t right_size = 0;

	/* if tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/* if tree has no children, return 1 */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* traverse left subtree */
	left_size = binary_tree_size(tree->left);
	/* traverse right subtree */
	right_size = binary_tree_size(tree->right);

	/* return the sum of the sizes of the subtrees */
	return (left_size + right_size + 1);
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level by level
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
