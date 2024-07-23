#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * getline - Reads an entire line from stream, storring the address of
 * the buffer containing the text into *lineptr. The buffer is
 * null-terminated and includes the newline character, if one was found
 *
 * @lineptr: A pointer to the buffer containing the read line
 * @n: The size of the buffer
 * @stream: The input stream to read from
 *
 * Return: The number of chractrers read, including the delimiter, but
 * not including the null byte. -1 on failure to read a  line
 * (including EoF condition)
 */

ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos, new_size;
	char *new_ptr;
	int c;

	if (lineptr == NULL || stream == NULL || n == NULL)
		return (-1);
	c = getc(stream);
	if (c == EOF)
		return (-1);
	if (*lineptr == NULL)
	{
		*lineptr = malloc(128);
		if (*lineptr == NULL)
			return (-1);
		*n = 128;
	}
	pos = 0;
	while (c != EOF)
	{
		if (pos + 1 >= *n)
		{
			new_size = *n + (*n >> 2);
			if (new_size < 128)
				new_size = 128;
			new_ptr = realloc(*lineptr, new_size);
			if (new_ptr == NULL)
				return (-1);
			*n = new_size;
			*lineptr = new_ptr;
		}
		((unsigned char *)(*lineptr))[pos++] = c;
		if (c == '\n')
			break;
		c = getc(stream);
	}
	(*lineptr)[pos] = '\0';
	return (pos);
}
