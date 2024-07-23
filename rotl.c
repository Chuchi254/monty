#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: double pointer to the stack
 * @line_number: the current line number in the file (unused).
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	(void)line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	first = *stack;
	last = *stack;

	while (last->next != NULL)
		last = last->next;

	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
}
