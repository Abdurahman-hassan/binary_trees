# include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root of the tree or subtree
 * A binary tree is full if each node has zero or two children.
 * Return: 1 if the tree is full, otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    int left_full = 0, right_full = 0;

    /* If tree is NULL, return 0 */
    if (tree == NULL)
        return (0);

    /* If tree has no children, return 1 */
    if (tree->left == NULL && tree->right == NULL)
        return (1);

    /* Recursively check if the left and right subtrees are full */
    left_full = binary_tree_is_full(tree->left);
    right_full = binary_tree_is_full(tree->right);

    /* If both subtrees are full, return 1 */
    if (left_full == 1 && right_full == 1)
        return (1);

    /* Otherwise, return 0 */
    return (0);
}
