#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: The current line number in the bytecode file
 * @arg: The argument to the push opcode, which should be an integer
 *
 * Description: Creates a new node with the given integer value and
 * adds it to the top of the stack. If the argument is not a valid
 * integer, prints an error message and exits with EXIT_FAILURE.
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	int n;
	stack_t *new_node, *current;

	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (current_mode == 0)
	{
		new_node->next = *stack;
		if (*stack != NULL)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
	else
	{
		if (*stack == NULL)
			*stack = new_node;
		else
		{
			current = *stack;
			while (current->next != NULL)
				current = current->next;
			current->next = new_node;
			new_node->prev = current;
		}
	}
}
