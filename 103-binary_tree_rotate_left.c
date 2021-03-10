#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs left-rotation on a binary tree
 * @tree: pointer to the root node of the tree
 * Return: pointer to the new root node if the rotated tree
 **/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp;

	if (!tree)
		return (NULL);

	tmp = tree->right;

	if (!tmp)
		return (tree);

	tmp->parent = tree->parent;
	if (tmp->left)
		tmp->left->parent = tree;
	tree->right = tmp->left;
	tmp->left = tree;
	tree->parent = tmp;
	return (tmp);
}
