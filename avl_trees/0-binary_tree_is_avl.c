#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 * 
 * Return: Height of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (!tree)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum allowed value for the current node.
 * @max: Maximum allowed value for the current node.
 * 
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
    if (!tree)
        return (1);

    if (tree->n <= min || tree->n >= max)
        return (0);

    return (is_bst(tree->left, min, tree->n) &&
            is_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 * 
 * Return: 1 if tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (!tree)
        return (0);

    if (!is_bst(tree, INT_MIN, INT_MAX))
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    if (abs(left_height - right_height) > 1)
        return (0);

    return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
