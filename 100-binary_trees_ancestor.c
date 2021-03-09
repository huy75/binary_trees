#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: a pointer to the node to measure the depth
 *
 * Return: depth of tree or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}

/**
 * binary_trees_ancestor - finds lowest common ancestor of two nodes
 * @first: pointer to first node
 * @second: pointer to second node
 *
 * Return: pointer to lowest common ancestor node of two given nodes
 * or NULL if no common ancestor found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *tmp_f, *tmp_s;
	int diff;

	if (!first || !second)
		return (NULL);

	diff = binary_tree_depth(first) - binary_tree_depth(second);

	tmp_f = (binary_tree_t *)first;
	tmp_s = (binary_tree_t *)second;

	/* second has more depth than first */
	while (diff < 0)
	{
		tmp_s = tmp_s->parent;
		diff++;
	}

	/* first has more depth than second */
	while (diff)
	{
		tmp_f = tmp_f->parent;
		diff--;
	}

	/* both are of the same depth */
	while (tmp_f && tmp_s)
	{
		if (tmp_f == tmp_s)
			return (tmp_f);
		tmp_f = tmp_f->parent;
		tmp_s = tmp_s->parent;
	}
	return (NULL);
}
