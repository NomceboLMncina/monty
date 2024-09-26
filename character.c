#include "monty.h"
#include "lists.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * pchar_handler - handles the pchar instruction
 * @stack: double pointer to the stack to push to
 * @line_n: number of the line in the file
 */

void pchar_handler(stack_t **stack, unsigned int line_n)
{
	stack_t *node = *stack;

	if (!node)
	{
		dprintf(STDERR_FILENO, PCHAR_FAIL, line_n);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (node->g < 0 || node->g > 127)
	{
		dprintf(STDERR_FILENO, PCHAR_RANGE, line_n);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	putchar(node->g);
	putchar('\n');
}

/**
 * pstr_handler - handles the pstr instruction
 * @stack: double pointer to the stack to push to
 * @line_n: number of the line in the file
 */

void pstr_handler(stack_t **stack, unsigned int line_n)
{
	stack_t *node = *stack;

	(void)line_n;

	if (!node)
	{
		putchar('\n');
		return;
	}

	while (node && node->g != 0 && node->g >= 0 && node->g <= 127)
	{
		putchar(node->g);
		node = node->nxt;
	}

	putchar('\n');
}
