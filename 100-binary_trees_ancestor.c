#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: First node
 * @second: Second node
 * Return: Pointer to the lowest common ancestor node of the two given nodes
 * or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *temp = NULL;

	/* Check if the nodes are valid */
	if (!first || !second)
		return (NULL);

	/* Traverse up the tree from the first node */
	while (first)
	{
		/* Traverse up the tree from the second node */
		temp = (binary_tree_t *)second;
		while (temp)
		{
			/* If the nodes are the same, return the common ancestor */
			if (first == temp)
				return ((binary_tree_t *)first);

			/* Move up the tree for the second node */
			temp = temp->parent;
		}

		/* Move up the tree for the first node */
		first = first->parent;
	}

	/* If no common ancestor is found, return NULL */
	return (NULL);
}
