#include "binary_trees.h"

avl_t *update_a_balance(avl_t **tree);

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree for removing a node
 * @value: Value to remove in the tree
 * Return: Pointer to the new root node of the tree after removing the value
 */
avl_t *avl_remove(avl_t *root, int value)
{
    avl_t *temp, *successor;

    if (root == NULL)
        return (NULL);

    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
        if (root->left && root->right) /* Node with two children */
        {
            successor = root->right;
            while (successor->left != NULL)
                successor = successor->left;
            root->n = successor->n;
            root->right = avl_remove(root->right, successor->n);
        }
        else /* Node with one or zero children */
        {
            temp = root->left ? root->left : root->right;
            if (temp == NULL) /* No child case */
            {
                temp = root;
                root = NULL;
            }
            else /* One child case */
            {
                *root = *temp;
            }
            free(temp);
        }
    }

    if (root == NULL)
        return (root);

    return update_a_balance(&root);
}

/**
 * update_a_balance - Balances an AVL tree from a given node
 * @tree: Double pointer to the node to balance from
 * Return: New root of the balanced subtree
 */
avl_t *update_a_balance(avl_t **tree)
{
    int balance;
    int balance_left;
    int balance_right;

    if (tree == NULL || *tree == NULL)
        return (NULL);

    balance = binary_tree_balance((const binary_tree_t *)*tree);
    balance_left = binary_tree_balance((const binary_tree_t *)(*tree)->left);
    balance_right = binary_tree_balance((const binary_tree_t *)(*tree)->right);

    /* Left heavy */
    if (balance > 1 && balance_left >= 0)
        return binary_tree_rotate_right((binary_tree_t *)*tree);

    /* Right heavy */
    if (balance < -1 && balance_right <= 0)
        return binary_tree_rotate_left((binary_tree_t *)*tree);

    /* Left-right case */
    if (balance > 1 && balance_left < 0)
    {
        (*tree)->left = binary_tree_rotate_left((binary_tree_t *)(*tree)->left);
        return binary_tree_rotate_right((binary_tree_t *)*tree);
    }

    /* Right-left case */
    if (balance < -1 && balance_right > 0)
    {
        (*tree)->right = binary_tree_rotate_right((binary_tree_t *)(*tree)->right);
        return binary_tree_rotate_left((binary_tree_t *)*tree);
    }

    return (*tree);
}
