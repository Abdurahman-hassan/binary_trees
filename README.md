# binary_trees
This repository, binary_trees, is a collaborative educational project created by students of Holberton School and ALX AFRICA. It serves as a comprehensive resource for learning and implementing binary trees, a fundamental concept in computer science.
Binary trees are a type of hierarchical data structure where each node has at most two children. There are several types of binary trees, each with its unique characteristics:
1. Full Binary Tree: A full binary tree is a special type of binary tree in which every parent node/internal node has either two or no children.
2. Perfect Binary Tree: A perfect binary tree is a type of binary tree in which every internal node has exactly two child nodes and all the leaf nodes are at the same level.
3. Balanced Binary Tree: A balanced binary tree is a binary tree structure in which the left and right subtrees of every node differ in height by no more than.
4. Complete Binary Tree: A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible.
5. Degenerate Binary Tree: A binary tree is said to be a degenerate binary tree or pathological binary tree if every internal node has only a single child.

## Functions

Here are some functions you need to write for this project:

1. `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);` - Creates a new binary tree node with the given value. Returns a pointer to the new node, or NULL on failure.

2. `binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);` - Inserts a new node as the left child of the given parent node. Returns a pointer to the new node, or NULL on failure or if the parent is NULL.

3. `binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);` - Inserts a new node as the right child of the given parent node. Returns a pointer to the new node, or NULL on failure or if the parent is NULL.

4. `void binary_tree_delete(binary_tree_t *tree);` - Deletes an entire binary tree. Does nothing if the tree is NULL.

5. `int binary_tree_is_leaf(const binary_tree_t *node);` - Checks if a node is a leaf. Returns 1 if the node is a leaf, 0 otherwise. If the node is NULL, returns 0.

6. `int binary_tree_is_root(const binary_tree_t *node);` - Checks if a node is the root. Returns 1 if the node is the root, 0 otherwise. If the node is NULL, returns 0.

7. `void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));` - Traverses a binary tree in pre-order (root, left, right) and calls the given function for each node. Does nothing if the tree or the function is NULL.

8. `void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));` - Traverses a binary tree in in-order (left, root, right) and calls the given function for each node. Does nothing if the tree or the function is NULL.

9. `void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));` - Traverses a binary tree in post-order (left, right, root) and calls the given function for each node. Does nothing if the tree or the function is NULL.

10. `size_t binary_tree_height(const binary_tree_t *tree);` - Measures the height of a binary tree. Returns 0 if the tree is NULL.

11. `size_t binary_tree_depth(const binary_tree_t *tree);` - Measures the depth of a node in a binary tree. Returns 0 if the tree is NULL.

12. `size_t binary_tree_size(const binary_tree_t *tree);` - Measures the size of a binary tree. Returns 0 if the tree is NULL.



12. `size_t binary_tree_depth(const binary_tree_t *tree);` - Measures the depth of a node in a binary tree. Returns 0 if the tree is NULL.

13. `size_t binary_tree_size(const binary_tree_t *tree);` - Measures the size of a binary tree. Returns 0 if the tree is NULL.

