#include "binary_trees.h"

/**
 * swap_nodes - Swaps two nodes in the heap
 * @a: The first node
 * @b: The second node
 */
void swap_nodes(heap_t *a, heap_t *b)
{
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}

/**
 * heapify_up - Fixes the heap after insertion
 * @node: The inserted node
 */
heap_t *heapify_up(heap_t *node)
{
    while (node->parent && node->n > node->parent->n)
    {
        swap_nodes(node, node->parent);
        node = node->parent;
    }
    return (node);
}

/**
 * find_insert_point - Finds the next available spot in the heap
 * @root: The root of the heap
 * Return: The parent node where the new node should be inserted
 */
heap_t *find_insert_point(heap_t *root)
{
    heap_t **queue = calloc(1024, sizeof(heap_t *));
    int front = 0, back = 0;

    if (!queue)
        return (NULL);

    queue[back++] = root;

    while (front < back)
    {
        heap_t *current = queue[front++];

        if (!current->left)
        {
            free(queue);
            return current;
        }

        if (!current->right)
        {
            free(queue);
            return current;
        }

        queue[back++] = current->left;
        queue[back++] = current->right;
    }

    free(queue);
    return (NULL);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *parent, *new_node;

    if (!root)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!(*root))
    {
        *root = new_node;
        return (new_node);
    }

    parent = find_insert_point(*root);
    if (parent)
    {
        new_node->parent = parent;
        if (!parent->left)
            parent->left = new_node;
        else
            parent->right = new_node;
    }

    new_node = heapify_up(new_node);

    return (new_node);
}
