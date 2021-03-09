#include "binary_trees.h"

/**
 * binary_tree_is_full - check if a binary tree is full
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if full, 0 if NULL or not full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int hl, hr;

	if (!tree)
		return (0);

	hl = tree->left ? 1 + binary_tree_is_full(tree->left) : 0;
	hr = tree->right ? 1 + binary_tree_is_full(tree->right) : 0;
	return (hl == hr);
}
