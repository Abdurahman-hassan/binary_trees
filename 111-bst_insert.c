#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 *         If the address stored in tree is NULL, the created node
 *         must become the root node.
 *         If the value is already present in the tree, it must be ignored
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL;

	if (!tree)
		return (NULL);
	/* if the tree is empty, create a new node as the root */
	if (!(*tree))
	{
		new_node = binary_tree_node(*tree, value);
		*tree = new_node;
		return (new_node);
	}
	/* if the value is less than the current node's value */
	/* insert into the left subtree */
	if (value < (*tree)->n)
	{
		/* if the left child is NULL, create a new node as the left child */
		if (!((*tree)->left))
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->left = new_node;
			return (new_node);
		}
		/* if the left child is not NULL, recursively insert into the left subtree */
		return (bst_insert(&((*tree)->left), value));
	}
	/* if the value is greater than current node's value insert into right subtr*/
	if (value > (*tree)->n)
	{
		/* if the right child is NULL, create a new node as the right child */
		if (!((*tree)->right))
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->right = new_node;
			return (new_node);
		}
		/* if the right child is not NULL recursively insert into the right subtr */
		return (bst_insert(&((*tree)->right), value));
	}
	/* if the value is already present in the tree ignore it and return NULL */
	return (NULL);
}
