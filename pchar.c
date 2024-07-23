#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: double pointer to the stack
 * @line_number: the current line number in the file
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;

	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", value);
}
