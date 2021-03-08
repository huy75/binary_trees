#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary tree using postorder traversal
 * @tree: pointer to the root
 * @func: a pointer to a function to call for each node
 * If tree or func is NULL, do nothing
 *
 * Return: none
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
