#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * main - Entry point of the Monty bytecode interpreter
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument string
 *
 * Return: 0 Always on success, exits with EXIT_FAILURE on error.
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *opcode, *arg;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		if (line[0] == '#')
			continue;
		opcode = strtok(line, " \n\t");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		arg = strtok(NULL, " \n\t");
		execute_instruction(opcode, arg, &stack, line_number);
	}

	free(line);
	fclose(file);
	free_stack(stack);
	return (0);
}

/**
 * execute_instruction - Executes the given opcode with the argument
 * @opcode: The opcode to execute
 * @arg: The argument to the opcode, if any
 * @stack: double pointer to the stack
 * @line_number: The current line number in they bytecode file
 *
 */
void execute_instruction(char *opcode, char *arg, stack_t **stack,
		unsigned int line_number)
{
	int i = 0;

	instruction_t instructions[] = {
		{"push", NULL},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", set_stack_mode},
		{"queue", set_queue_mode},
		{NULL, NULL}
	};

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			if (strcmp(opcode, "push") == 0)
				push(stack, line_number, arg);
			else
				instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
