#include "monty.h"
#include "lists.h"

/**
 * get_func - selects the right function
 * @parse: line from the byte code file passed to main
 * Return: pointer to the selected function, or NULL on failure
 */
void (*get_func(char **))(stack_t **, unsigned int)
{
	instruction func_array[] = {
		{"push", push_handler},
		{"pall", pall_handler},
		{"pint", pint_handler},
		{"pop", pop_handler},
		{"swap", swap_handler},
		{"add", add_handler},
		{"nop", nop_handler},
		{"sub", sub_handler},
		{"div", div_handler},
		{"mul", mul_handler},
		{"mod", mod_handler},
		{"pchar", pchar_handler},
		{"pstr", pstr_handler},
		{"rotl", rotl_handler},
		{"rotr", rotr_handler},
		{"stack", stack_handler},
		{"queue", queue_handler},
		{NULL, NULL}
	};

	int codes = 17, x;

	for (x = 0; x < codes; x++)
	{
		if (strcmp(func_array[x].opcode, parse[0]) == 0)
		{
			return (func_array[x].f);
		}
	}
	return (NULL);
}

/**
 * push_handler - handles the push instruction
 * @stack: double pointer to the stack to push to
 * @line_n: number of the line in the file
 */
void push_handler(stack_t **stack, unsigned int line_n)
{
	stack_t *new;
	int number = 0, x;

	if (data.words[1] == NULL)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_n);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	for (x = 0; data.words[1][x]; x++)
	{
		if (isalpha(data.words[1][x]) != 0)
		{
			dprintf(STDERR_FILENO, PUSH_FAIL, line_n);
			free_all(1);
			exit(EXIT_FAILURE);
		}
	}
	number = atoi(data.words[1]);

	if (data.qflag == 0)
		new = add_dnodeint(stack, number);
	else if (data.qflag == 1)
		new = add_dnodeint_end(stack, number);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall_handler - handles the pall instruction
 * @stack: double pointer to the stack to push to
 * @line_n: number of the line in the file
 */
void pall_handler(stack_t **stack, unsigned int line_n)
{
	(void)line_n;
	if (*stack)
		print_dlistint(*stack);
}

