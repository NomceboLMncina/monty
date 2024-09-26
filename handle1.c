#include "monty.h"
#include "lists.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * pint_handler - handles the pint instruction
 * @stack: double pointer to the stack to push to
 * @line_n: number of the line in the file
 */

void pint_handler(stack_t **stack, unsigned int line_n)
{
	stack_t *l = *stack;

	if (!l)
	{
		dprintf(STDERR_FILENO, PINT_FAIL, line_n);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", l->g);
}

/**
 * pop_handler - handles the pop instruction
 * @stack: double pointer to the stack to push to
 * @line_n: number of the line in the file
 */

void pop_handler(stack_t **stack, unsigned int line_n)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		dprintf(STDERR_FILENO, POP_FAIL, line_n);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	delete_dnodeint_at_index(stack, 0);
}

/**
 * swap_handler - handles the swap instruction
 * @stack: double pointer to the stack to push to
 * @line_n: number of the line in the file
 */

void swap_handler(stack_t **stack, unsigned int line_n)
{
	stack_t *temp = *stack, *node = NULL;
	int number;

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SWAP_FAIL, line_n);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	temp = get_dnodeint_at_index(*stack, 0);
	number = temp->g;
	delete_dnodeint_at_index(stack, 0);
	node = insert_dnodeint_at_index(stack, 1, number);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * add_handler - handles the add instruction
 * @stack: double pointer to the stack to push to
 * @line_n: number of the line in the file
 */

void add_handler(stack_t **stack, unsigned int line_n)
{
	int sum = 0;
	stack_t *node = NULL;
	stack_t *node0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, ADD_FAIL, line_n);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	sum = node0->g + node1->g;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, sum);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop_handler - handles the nop instruction
 * @stack: double pointer to the stack to push to
 * @line_n: number of the line in the file
 */

void nop_handler(stack_t **stack, unsigned int line_n)
{
	(void)stack;
	(void)line_n;
}

