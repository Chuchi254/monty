#include "monty.h"

int current_mode = 0;

/**
 * set_stack_mode - sets the format of the data to a stack (LIFO).
 * @stack: double pointer to the stack (unused).
 * @line_number: the current line number in the file (unused)
 */

void set_stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	current_mode = 0;
}

/**
 * set_queue_mode - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the stack (unused)
 * @line_number: the current line number in the file (unused)
 */

void set_queue_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	current_mode = 1;
}
