#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element
 * of the stack 
 * @stack: double pointer to the stack
 * @line_number: the current line number in the file
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = (*stack)->next;

	if (first->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	second->n %= first->n;
	*stack = second;
	second->prev = NULL;
	free(first);
}
