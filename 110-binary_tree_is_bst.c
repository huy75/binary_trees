#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst - checks if a binary tree is a valid binary search tree.
 * @tree: pointer to the root node of the tree.
 * @lo: the value of the smallest node visited thus far.
 * @hi: the value of the largest node visited this far.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int is_bst(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst(tree->left, lo, tree->n - 1) &&
			is_bst(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid binary search tree.
 * @tree: pointer to the root node of the tree.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX));
}
