#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"


/**
 * is_heap - checks if binary tree is Binary Max Heap
 * @tree: pointer to root node of the tree
 * Return: 1 if heap, 0 if not or NULL
 **/
int is_heap(const binary_tree_t *tree)
{
	if (!tree->left && !tree->right)
		return (1);
	if (!tree->right)
		return (tree->n >= tree->left->n);
	if (tree->n >= tree->left->n && tree->n >= tree->right->n)
		return (is_heap(tree->left) && is_heap(tree->right));
	else
		return (0);
}


/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to root node of the tree
 * Return: 1 if true 0 if false
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_is_complete(tree) && is_heap(tree));
}
