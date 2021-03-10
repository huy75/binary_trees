#include "binary_trees.h"

/**
 * bst_insert - inserts a value to BST
 * @tree: a double pointer to the root node of the BST
 * @value: the value to store in the node to be inserted
 * Return: return a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new = NULL;

	if (!tree || !(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	new = *tree;
	if (value == new->n)
		return (NULL);
	if (value > new->n)
	{
		if (new->right)
			return (bst_insert(&(new->right), value));

		new->right = binary_tree_node(new, value);
		return (new->right);
	}
	if (value < new->n)
	{
		if (new->left)
			return (bst_insert(&(new->left), value));

		new->left = binary_tree_node(new, value);
		return (new->left);
	}
	return (NULL);
}
