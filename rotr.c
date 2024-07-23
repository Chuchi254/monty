#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: double pointer to the stack
 * @line_number: the current line number in the file (unused).
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *second_last, *last;

	(void)line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	second_last = NULL;

	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}

	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = NULL;
	*stack = last;
}
