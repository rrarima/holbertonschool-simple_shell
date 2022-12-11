#include "main.h"

/**
 * main - Entry point of program.
 *        main function initializes the lineptr buffer and the args array,
 *        then enters a loop that reads input, parses it, and executes the
 *        command specified by the input.
 *
 * Return: 0 if the program ran successfully or exits when
 *         when read_input returns an error.
  */

int main(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t chars_read = 0;
	char *args[1024];

	while (1)
	{
		read_input(&lineptr, &n, &chars_read);
		if (chars_read == -1)
		{
			break;
		}
		parse_input(lineptr, args, n, chars_read);
	}

	free(lineptr);
	return (0);
}
