#include "monty.h"
#include "lists.h"

/**
 * free_all - custom memory handling function
 * @z: flag to indicate what to free
 */

void free_all(int z)
{
	if (data.line)
	{
		free(data.line);
		data.line = NULL;
		free_everything(data.words);
		data.words = NULL;
	}

	if (z)
	{
		if (data.stack)
		{
			free_dlistint(data.stack);
			data.stack = NULL;
		}
		if (data.fptr)
		{
			fclose(data.fptr);
			data.fptr = NULL;
		}
	}
}

