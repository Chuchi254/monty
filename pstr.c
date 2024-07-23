#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack,
 * followed y a new line.
 * @stack: double pointer to the stack
 * @line_number: the current line number in the file
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int value;

	(void)line_number;
	while (current != NULL)
	{
		value = current->n;
		if (value <= 0 || value > 127)
			break;
		printf("%c", value);
		current = current->next;
	}
	printf("\n");
}
