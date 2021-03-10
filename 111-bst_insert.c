#include "binary_trees.h"

/**
 * node_insert - inserts a node
 * @root: the root of BST
 * @new_node: a new node to be added
 * @value: value of the node to insert to BST
 * Return: reture the propert node to be insert
 */
bst_t *node_insert(bst_t *root, bst_t *new_node, int value)
{
	if (!root)
		return (new_node);
	if (!root->left || !root->right)
		new_node->parent = root;
	if (value < root->n)
		root->left = node_insert(root->left, new_node, value);
	else if (value > root->n)
		root->right = node_insert(root->right, new_node, value);
	return (root);
}
/**
 * bst_insert - inserts a value to BST
 * @tree: is a double pointer to the root node of the BST
 * @value: the value to store in the node to be inserted
 * Return: return a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *root;

	root = *tree;

	new_node = (bst_t *)binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!tree || !root)
	{
		*tree = new_node;
		return (new_node);
	}

	node_insert(root, new_node, value);
	return (new_node);
}
