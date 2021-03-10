#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to root node of tree to measure size
 * Return: size of binary tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}


/**
 * is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 * @index: index of the node
 * @num: number of the nodes
 *
 * Return: 1 if the tree is complete, otherwise 0
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t num)
{
	if (tree == NULL)
		return (1);

	if (index >= num)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, num) *
		is_complete(tree->right, 2 * index + 2, num));
}


/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: Pointer to root node of tree to check
 * Return: 1, 0 if NULL or not complete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{

	size_t count;
	size_t index = 0;

	if (tree == NULL)
		return (0);

	count = binary_tree_size(tree);

	return (is_complete(tree, index, count));
}
