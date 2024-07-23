#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * _div - divides the second top element of the stack by the top
 * element of the stack
 * @stack: double pointer to the stack
 * @line_number: the current line number in the file
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = (*stack)->next;

	if (first->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	second->n /= first->n;
	*stack = second;
	second->prev = NULL;
	free(first);
}
