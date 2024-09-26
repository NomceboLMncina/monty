#include "monty.h"
#include "lists.h"

data_t data = DATA_INIT;

/**
 * monty - helper function for main function
 * @args: pointer to struct of arguments from main
 * Description: opens and reads from the file containing opcodes
 */

void monty(args_t *args)
{
	size_t en = 0;
	int o = 0;
	void (*code_func)(stack_t **, unsigned int);

	if (args->ac != 2)
	{
		dprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
	}
	data.fptr = fopen(args->av, "r");
	if (!data.fptr)
	{
		dprintf(STDERR_FILENO, FILE_ERROR, args->av);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		args->line_n++;
		o = getline(&(data.line), &en, data.fptr);
		if (o < 0)
			break;
		data.words = strtow(data.line);
		if (data.words[0] == NULL || data.words[0][0] == '#')
		{
			free_all(0);
			continue;
		}
		code_func = get_func(data.words);
		if (!code_func)
		{
			dprintf(STDERR_FILENO, UNKNOWN, args->line_n, data.words[0]);
			free_all(1);
			exit(EXIT_FAILURE);
		}
		code_func(&(data.stack), args->line_n);
		free_all(0);
	}
	free_all(1);
}

/**
 * main - entry point for monty bytecode interpreter
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int argc, char *argv[])
{
	args_t args;
	args.av = argv[1];
	args.ac = argc;
	args.line_n = 0;

	monty(&args);

	return (EXIT_SUCCESS);
}
