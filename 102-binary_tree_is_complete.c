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
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: Pointer to root node of tree to check
 * Return: 1, 0 if NULL or not complete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue, *current;
	int first = 1, start = 0, index = 0, size;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);

	queue = malloc(sizeof(binary_tree_t *) * size);
	if (!queue)
		return (0);

	queue[start] = (binary_tree_t *)tree;
	index++;

	while (start < size)
	{
		current = queue[start++];
		if (current->left)
			queue[index++] = current->left;
		if (current->right)
			queue[index++] = current->right;
		else
			if (current->left && !first)
			{
				free(queue);
				return (0);
			}

		if (current->left && !current->right)
			first = 0;
		if (!current->left)
			if (current->right)
			{
				free(queue);
				return (0);
			}
	}
	free(queue);
	return (1);
}
