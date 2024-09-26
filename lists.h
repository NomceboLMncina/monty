#ifndef LISTS_H
#define LISTS_H

#include "monty.h"

size_t dlistint_len(const dlistint_t *f);
dlistint_t *add_dnodeint(dlistint_t **l, const int g);
size_t print_dlistint(const dlistint_t *f);
int delete_dnodeint_at_index(dlistint_t **l, unsigned int m);
dlistint_t *get_dnodeint_at_index(dlistint_t *l, unsigned int m);

dlistint_t *insert_dnodeint_at_index(dlistint_t **f, unsigned int p, int g);
dlistint_t *add_dnodeint_end(dlistint_t **l, const int g);
void free_dlistint(dlistint_t *l);

#endif

