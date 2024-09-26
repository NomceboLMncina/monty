#include "monty.h"

/**
 * dlistint_len - returns the number of nodes in a doubly linked list
 * @f: pointer to the list
 * Return: number of nodes
 */

size_t dlistint_len(const dlistint_t *f)
{
	size_t nodes = 0;

	if (!f)
		return (0);

	while (f)
	{
		nodes++;
		f = f->nxt;
	}

	return (nodes);
}

/**
 * add_dnodeint - adds a new node at the beginning of a doubly linked list
 * @l: double pointer to the list
 * @n: data to insert in the new node
 * Return: the address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint(dlistint_t **l, const int g)
{
	dlistint_t *new;

	if (!l)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->g = g;

	new->nxt = *l;
	new->prv = NULL;

	if (*l)
		(*l)->prv = new;

	*l = new;

	return (new);
}

/**
 * print_dlistint - prints a doubly linked list
 * @h: pointer to the list
 * Return: number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *f)
{
	size_t nodes = 0;

	if (!f)
		return (0);

	while (f)
	{
		printf("%d\n", f->g);
		f = f->nxt;
		nodes++;
	}

	return (nodes);
}

/**
 * delete_dnodeint_at_index - deletes a node in a doubly linked list
 * at a given index
 * @l: double pointer to the list
 * @m: index of the node to delete
 * Return: 1 on success, -1 on failure
 */

int delete_dnodeint_at_index(dlistint_t **l, unsigned int m)
{
	dlistint_t *temp = *l;
	unsigned int x = 0;

	if (!m)
	{
		(*l) = temp->nxt;
		if (temp->nxt)
			temp->nxt->prv = NULL;
		temp->nxt = NULL;
		free(temp);
		return (1);
	}

	while (x < m)
	{
		temp = temp->nxt;
		x++;
		if (!temp)
			return (0);
	}

	temp->prv->nxt = temp->nxt;
	if (temp->nxt)
		temp->nxt->prv = temp->prv;
	free(temp);

	return (1);
}

/**
 * get_dnodeint_at_index - gets the nth node of a doubly linked list
 * @l: pointer to the list
 * @m: index of the node to return
 * Return: address of the node, or if it does not exist, NULL
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *l, unsigned int m)
{
	unsigned int x = 0;

	if (!l)
		return (NULL);

	while (l && x < m)
	{
		l = l->nxt;
		x++;
	}

	return (l ? l : NULL);
}
