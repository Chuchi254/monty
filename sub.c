#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the second top
 * element of the stack
 * @stack: double pointer to the stack
 * @line_number: the current line number in the file
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	second->n -= first->n;
	*stack = second;
	second->prev = NULL;
	free(first);
}
