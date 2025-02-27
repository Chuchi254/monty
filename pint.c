#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 * @stack: double pointer to the stack
 * @line_number: the current line number in the file
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
