#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs right-rotation on a binary tree
 * @tree: pointer to the root node of the tree
 * Return: pointer to the new root node of the rotated tree
 **/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *parent, *b;

	if (!tree)
		return (NULL);

	parent = tree->parent;
	b = tree->left;

	tree->left = b->right;
	if (b->right)
		b->right->parent = tree;

	b->right = tree;
	tree->parent = b;
	b->parent = parent;

	if (parent)
	{
		if (parent->left == tree)
			parent->left = b;
		else
			parent->right = b;
	}
	return (b);
}
