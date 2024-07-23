#include <stdlib.h>
#include "monty.h"

/**
 * free_stack - Frees all the nodes in the stack
 * @stack: Pointer to the head of the stack
 *
 * Description: Frees all the nodes in the stack to prevent memory leaks.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/**
 * is_number - Checks if a string is a valid integer
 * @str: The string to check
 * Return: 1 if the string is a valid integer, 0 otherwise
 */
int is_number(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
