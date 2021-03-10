#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs left-rotation on a binary tree
 * @tree: pointer to the root node of the tree
 * Return: pointer to the new root node if the rotated tree
 **/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *parent, *a;

	if (!tree)
		return (NULL);

	parent = tree->parent;
	a = tree->right;

	tree->right = a->left;
	if (a->left)
		a->left->parent = tree;

	a->left = tree;
	tree->parent = a;
	a->parent = parent;

	if (parent)
	{
		if (parent->left == tree)
			parent->left = a;
		else
			parent->right = a;
	}
	return (a);
}
