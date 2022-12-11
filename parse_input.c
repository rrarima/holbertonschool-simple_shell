#include "main.h"

/**
 * parse_input - This function takes the input line read by
 *               read_input and parses it into individual arguments.
 *               It stores the parsed arguments in the args array.
 *
 * @lineptr: Pointer to the buffer that holds the input line
 * @args: Array of pointers to the individual arguments in the input line
 * @n: Maximum number of characters that the input line can have
 * @chars_read: Actual number of characters in the input line
 *
 */

void parse_input(char *lineptr, char *args[], size_t n, ssize_t chars_read)
{
	size_t i;
	char *token = strtok(lineptr, " \t\n\r");

	if (lineptr[chars_read - 1] == '\n')
	{
		lineptr[chars_read - 1] = '\0';
	}
	if (token != NULL)
	{
		i = 0;
		while (i < n && token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " \t\n\r");
			i = i + 1;
		}
		if (strncmp(lineptr, "exit", 4) == 0)
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		args[i] = NULL;
		fork_child(lineptr, args);
	}
}
