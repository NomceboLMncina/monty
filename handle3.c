#include "monty.h"
#include "lists.h"

/**
 * rotl_handler - handles the instruction
 * @stack: double pointer to the stack to push to
 * @line_n: number of the line in the file
 */

void rotl_handler(stack_t **stack, unsigned int line_n)
{
	stack_t *temp = *stack;
	int number  = 0;

	(void)line_n;

	if (*stack == NULL)
		return;
	temp = get_dnodeint_at_index(*stack, 0);
	number = temp->g;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint_end(stack, number);
}

/**
 * rotr_handler - handles the instruction
 * @stack: double pointer to the stack to push to
 * @line_n: number of the line in the file
 */

void rotr_handler(stack_t **stack, unsigned int line_n)
{
	stack_t *temp = *stack;
	int number = 0, en = dlistint_len(*stack);

	(void)line_n;

	if (*stack == NULL)
		return;
	temp = get_dnodeint_at_index(*stack, en - 1);
	number = temp->g;
	delete_dnodeint_at_index(stack, en - 1);
	add_dnodeint(stack, number);
}

/**
 * stack_handler - handles the stack instruction
 * @stack: double pointer to the stack to push to
 * @line_n: number of the line in the file
 */

void stack_handler(stack_t **stack, unsigned int line_n)
{
	(void)stack;
	(void)line_n;
	data.qflag = 0;
}


/**
 * queue_handler - handles the queue instruction
 * @stack: double pointer to the stack to push to
 * @line_n: number of the line in the file
 */

void queue_handler(stack_t **stack, unsigned int line_n)
{
	(void)stack;
	(void)line_n;
	data.qflag = 1;
}

