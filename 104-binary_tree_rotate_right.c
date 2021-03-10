#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs right-rotation on a binary tree
 * @tree: pointer to the root node of the tree
 * Return: pointer to the new root node of the rotated tree
 **/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp;

	if (!tree)
		return (NULL);

	tmp = tree->left;

	if (!tmp)
		return (tree);

	tmp->parent = tree->parent;
	if (tmp->right)
		tmp->right->parent = tree;
	tree->left = tmp->right;
	tmp->right = tree;
	tree->parent = tmp;
	return (tmp);
}
