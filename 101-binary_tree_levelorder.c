#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to root node of tree to measure size
 *
 * Return: size of binary tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_levelorder - goes through a binary tree with levelorder traversal
 * @tree: pointer to the root node of the tree
 * @func: a pointer to the function to call for each node
 * If tree or func is NULL, do nothing
 *
 * Return: none
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	binary_tree_t *current;
	int start = 0, index = 0, size;

	if (!tree || !func)
		return;

	size = binary_tree_size(tree);

	queue = malloc(sizeof(binary_tree_t *) * size);
	if (!queue)
		return;

	queue[start] = (binary_tree_t *)tree;
	index++;

	while (start < size)
	{
		current = queue[start];
		func(current->n);
		start++;

		if (current->left)
		{
			queue[index] = current->left;
			index++;
		}
		if (current->right)
		{
			queue[index] = current->right;
			index++;
		}
	}
	free(queue);
}
