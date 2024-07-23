#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: the current line number in the file
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	first->prev = second;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	*stack = second;
}
