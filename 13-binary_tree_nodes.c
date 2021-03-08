#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the nodes with at least 1 child in a binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: number of nodes, 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);

	return (1+ binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
