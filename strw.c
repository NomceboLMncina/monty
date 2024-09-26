#include "monty.h"
#include "lists.h"

/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 * Return: number of words
 */

int count_word(char *s)
{
	int fg, v, u;

	fg = 0;
	w = 0;

	for (v = 0; s[v] != '\0'; v++)
	{
		if (s[v] == ' ')
			fg = 0;
		else if (fg == 0)
		{
			fg = 1;
			u++;
		}
	}

	return (u);
}

/**
 * **strtow - splits a string into words
 * @str: string to split
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */

char **strtow(char *str)
{
	char **matrix, *tmp;
	int x, k = 0, en = 0, words, v = 0, start, end;

	en = strlen(str);
	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (x = 0; x <= en; x++)
	{
		if (isspace(str[x]) || str[x] == '\0' || str[x] == '\n')
		{
			if (v)
			{
				end = x;
				tmp = (char *) malloc(sizeof(char) * (v + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[k] = tmp - v;
				k++;
				v = 0;
			}
		}
		else if (v++ == 0)
			start = x;
	}

	matrix[k] = NULL;

	return (matrix);
}

/**
 * free_everything - frees arrays of strings
 * @args: array of strings to free
 */

void free_everything(char **args)
{
	int x;

	if (!args)
		return;

	for (x = 0; args[x]; x++)
		free(args[x]);

	free(args);
}
