#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s – A doubly linked list representation of a stack (or queue)
 * @n: An integer
 * @prv: Points to the previous element of the stack (or queue)
 * @nxt: Points to the next element of the stack (or queue)
 * Description: Doubly linked list node structure for stack,
 * queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int g;
	struct stack_s *prv;
	struct stack_s *nxt;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function for stack,
 * queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_n);
} instruction_t;

/**
 * struct args_s – A structure of arguments from main
 * @av: A name of the file from the command line
 * @ac: A number of arguments from main
 * @line_n: A number of the current line in the file
 * Description: arguments passed to main from the command line
 * used in different functions, organized in a structure for clarity
 */

typedef struct args_s
{
	char *av;
	int ac;
	unsigned int line_n;
} args_t;

/**
 * struct data_s - External data to access inside functions
 * @line: A line from the file
 * @words: A parsed line
 * @stack: A pointer to the stack
 * @qflag: A flag for queue or stack
 * @fptr: A file pointer
 */

typedef struct data_s
{
	char *line;
	char **words;
	stack_t *stack;
	FILE *fptr;
	int qflag;
} data_t;

typedef stack_t dlistint_t;

extern data_t data;

#define DATA_INIT {NULL, NULL, NULL, NULL, 0}

#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"
#define PINT_FAIL "L%u: can't print, stack is empty\n"
#define POP_FAIL "L%u: can't pop an empty stack\n"
#define SWAP_FAIL "L%u: can't swap, stack is too short\n"
#define ADD_FAIL "L%u: can't add, stack is too short\n"
#define SUB_FAIL "L%u: can't sub, stack is too short\n"
#define DIV_FAIL "L%u: can't div, stack is too short\n"
#define DIV_ZERO "L%u: division by zero\n"
#define MUL_FAIL "L%u: can't mul, stack is too short\n"
#define MOD_FAIL "L%u: can't mod, stack is too short\n"
#define PCHAR_FAIL "L%u: can't pchar, stack is empty\n"
#define PCHAR_RANGE "L%u: can't pchar, value is out of range\n"

void monty(args_t *args);

void (*get_func(char **parsed))(stack_t **, unsigned int);
void push_handler(stack_t **stack, unsigned int line_n);
void pall_handler(stack_t **stack, unsigned int line_n);

void pint_handler(stack_t **stack, unsigned int line_n);
void pop_handler(stack_t **stack, unsigned int line_n);
void swap_handler(stack_t **stack, unsigned int line_n);
void add_handler(stack_t **stack, unsigned int line_n);
void nop_handler(stack_t **stack, unsigned int line_n);

void sub_handler(stack_t **stack, unsigned int line_n);
void div_handler(stack_t **stack, unsigned int line_n);
void mul_handler(stack_t **stack, unsigned int line_n);
void mod_handler(stack_t **stack, unsigned int line_n);

void rotl_handler(stack_t **stack, unsigned int line_n);
void rotr_handler(stack_t **stack, unsigned int line_n);
void stack_handler(stack_t **stack, unsigned int line_n);
void queue_handler(stack_t **stack, unsigned int line_n);

void pchar_handler(stack_t **stack, unsigned int line_n);
void pstr_handler(stack_t **stack, unsigned int line_n);

int count_word(char *s);
char **strtow(char *str);
void free_everything(char **args);

void free_all(int z);

#endif
