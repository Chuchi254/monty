#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * mul - multiplies the second top element of the stack by the top
 * element of the stack
 * @stack: double pointer to the stack
 * @line_number: the current line number in the file
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = (*stack)->next;

	second->n *= first->n;
	*stack = second;
	second->prev = NULL;
	free(first);
}
