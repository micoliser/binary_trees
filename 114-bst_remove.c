#include "binary_trees.h"

/**
 * _remove - removes a node from a tree
 * @root: the root
 * @to_remove: the node to remove
 *
 * Return: new root
 */
bst_t *_remove(bst_t *root, bst_t *to_remove)
{
	bst_t *temp;

	if (to_remove->right)
		temp = to_remove->right;
	else
		temp = to_remove->left;
	while (temp->left)
		temp = temp->left;
	temp->parent->left = NULL;
	temp->parent = to_remove->parent;
	temp->right = to_remove->right;
	if (temp->right)
		temp->right->parent = temp;
	temp->left = to_remove->left;
	if (temp->left)
		temp->left->parent = temp;
	if (to_remove->parent)
	{
		if (to_remove->parent->left == to_remove)
			to_remove->parent->left = temp;
		else
			to_remove->parent->right = temp;
	}
	if (to_remove == root)
	{
		free(to_remove);
		return (temp);
	}
	else
	{
		free(to_remove);
		return (root);
	}
}

/**
 * bst_remove - removes a node from a binary search tree
 * @root: root node tree
 * @value: value to remove
 *
 * Return: a pointer to new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *to_remove, *temp;

	if (!root)
		return (NULL);
	to_remove = root;
	while (to_remove)
	{
		if (to_remove->n == value)
			break;
		else if (to_remove->n < value)
			to_remove = to_remove->right;
		else
			to_remove = to_remove->left;
	}
	if (to_remove)
	{
		temp = _remove(root, to_remove);
		return (temp);
	}
	return (NULL);
}
