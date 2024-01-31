#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal
 *
 * @tree: pointer to the root node of the tree to traverse
 * @arr: pointer to a function to call for each node
 * @idx: pointer to a function to call for each node
 *
 * Return: Nothing
 */

void binary_tree_inorder2(const binary_tree_t *tree, int *arr, size_t *idx)
{
	/* if tree or func is NULL, do nothing */
	if (tree == NULL)
		return;
	/* traverse left subtree */
	binary_tree_inorder2(tree->left, arr, idx);
	/* call func on current node */
	arr[(*idx)++] = tree->n;
	/* traverse right subtree */
	binary_tree_inorder2(tree->right, arr, idx);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid
 *
 * @tree: pointer to the root node of the tree or subtree
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	size_t tree_sz = binary_tree_size(tree), i = 0;
	int *arr;

	if (tree == NULL)
		return (0);
	arr = malloc(sizeof(int) * tree_sz);
	if (arr == NULL)
		return (0);
    binary_tree_inorder2(tree, arr, &i);
    for (i = 1; i < tree_sz; ++i)
        if (arr[i] <= arr[i-1])
        {
            free(arr);
            return (0);
        }
    free(arr);
    return (1);
}
