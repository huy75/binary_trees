#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of tree, 0 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t hl;
	size_t hr;

	if (!tree)
		return (0);

	hl = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	hr = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (hl > hr ? hl : hr);
}

/**
 * each_level - prints each level
 * @tree: pointer to root of tree
 * @func: function to be called on each node
 * @level: the tree depth level to print
 */
void each_level(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (!level)
		func(tree->n);
	else
	{
		each_level(tree->left, func, level - 1);
		each_level(tree->right, func, level - 1);
	}
}


/**
 * binary_tree_levelorder - goes through a binary tree using levelorder traversal
 * @tree: pointer to the root node of the tree
 * @func: a pointer to the function to call for each node
 * If tree or func is NULL, do nothing
 *
 * Return: none
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, idx;

	if (!tree || !func)
		return;

	h = binary_tree_height(tree);
	for (idx = 0; idx <= h; idx++)
		each_level(tree, func, idx);
}
