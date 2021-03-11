#include "binary_trees.h"
#include "limits.h"
#include "14-binary_tree_balance.c"

/**
 * is_avl - checks if a binary tree is a valid AVL tree.
 * @tree: pointer to the root node of the tree.
 * @lo: the value of the smallest node visited thus far.
 * @hi: the value of the largest node visited this far.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int is_avl(const binary_tree_t *tree, int lo, int hi)
{
	int balance;

	if (tree->left)
	{
		if (tree->left->n < lo || tree->left->n > hi)
			return (0);
		if (!is_avl(tree->left, lo, tree->n - 1))
			return (0);
	}
	if (tree->right)
	{
		if (tree->right->n < lo || tree->right->n > hi)
			return (0);
		if (!is_avl(tree->right, tree->n + 1, hi))
			return (0);
	}
	balance = binary_tree_balance(tree);
	return (balance >= -1 && balance <= 1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree.
 * @tree: pointer to the root node of the tree.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl(tree, INT_MIN, INT_MAX));
}
