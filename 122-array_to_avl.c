#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: a pointer to the first element of the array
 * @size: the number of element in the array
 *
 * Return: returns pointer to the root node of AVL
 * or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t idx;

	if (!size || !array)
		return (NULL);
	for (idx = 0; idx < size; idx++)
	{
		avl_insert(&tree, array[idx]);
	}
	return (tree);
}
