#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);
void binary_tree_delete_node(binary_tree_t *node);
void heapify_down(heap_t *node);
heap_t *get_last_node(heap_t *root, size_t size);
int heap_extract(heap_t **root);

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node, 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last;
	size_t size;

	if (!root || !*root)
		return (0);

	value = (*root)->n; /* Save the value to return it later. */
	size = binary_tree_size(*root);
	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	/* Get the last node in level-order traversal. */
	last = get_last_node(*root, size);

	/* Replace root with the last node. */
	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	last->left = (*root)->left;
	last->right = (*root)->right;
	if (last->left)
		last->left->parent = last;
	if (last->right)
		last->right->parent = last;

	free(*root);
	*root = last;
	last->parent = NULL;

	heapify_down(*root); /* Restore the heap property by heapifying down. */

	return (value);
}

/**
 * get_last_node - gets the last node in a binary heap
 * @root: the root of the heap
 * @size: the size of the heap
 * Return: the last node in the heap
 */
heap_t *get_last_node(heap_t *root, size_t size)
{
	heap_t **queue = calloc(size, sizeof(*queue));
	int front = 0, rear = 0;
	heap_t *node = NULL;

	if (!queue)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		node = queue[front++];
		if (node->left)
			queue[rear++] = node->left;
		if (node->right)
			queue[rear++] = node->right;
	}

	free(queue);
	return (node);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * heapify_down - restores the heap property by moving the node down the tree
 * @node: pointer to the root node of the heap
 */
void heapify_down(heap_t *node)
{
	heap_t *largest = NULL;
	int temp;

	if (!node)
		return;

	while (1)
	{
		largest = node;
		if (node->left && node->left->n > largest->n)
			largest = node->left;
		if (node->right && node->right->n > largest->n)
			largest = node->right;
		if (largest == node)
			break;
		/* Swap the values of node and largest. */
		temp = node->n;
		node->n = largest->n;
		largest->n = temp;
		/* Move down to the largest child. */
		node = largest;
	}
}

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: pointer to the new node, NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
