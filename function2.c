#include "monty.h"
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a node at a given index
 * in a doubly linked list
 * @f: double pointer to the list
 * @p: index of the node to insert
 * @g: data to insert
 * Return: address of the new node, or NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **f, unsigned int p, int g)
{
	unsigned int x;
	dlistint_t *new;
	dlistint_t *temp = *f;

	if (p == 0)
		return (add_dnodeint(f, g));

	for (x = 0; temp && x < p; x++)
	{
		if (x == p - 1)
		{
			if (temp->nxt == NULL)
				return (add_dnodeint_end(f, g));
			new = malloc(sizeof(dlistint_t));
			if (!new || !f)
				return (NULL);
			new->g = g;
			new->nxt = NULL;
			new->nxt = temp->nxt;
			new->prv = temp;
			temp->nxt->prv = new;
			temp->nxt = new;
			return (new);
		}
		else
			temp = temp->nxt;
	}

	return (NULL);
}

/**
 * add_dnodeint_end - adds a new node at the end of a doubly linked list
 * @l: double pointer to the list
 * @g: data to insert in the new node
 * Return: the address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **l, const int g)
{
	dlistint_t *new;
	dlistint_t *temp = *l;

	if (!l)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->g = g;
	new->nxt = NULL;

	if (*l == NULL)
	{
		new->prv = NULL;
		*l = new;
		return (new);
	}

	while (temp->nxt)
		temp = temp->nxt;

	temp->nxt = new;
	new->prv = temp;

	return (new);
}

/**
 * free_dlistint - frees a doubly linked list
 * @l: pointer to the list to free
 */

void free_dlistint(dlistint_t *l)
{
	dlistint_t *temp;

	while (l)
	{
		temp = l->nxt;
		free(l);
		l = temp;
	}
}

