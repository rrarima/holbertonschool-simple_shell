#include "main.h"

/**
 * read_input - This function reads a line of input
 *             from the user and saves it in the
 *
 * @lineptr: Pointer to a buffer that will hold
 *           the input line read by the function
 *
 * @n: Maximum number of characters that the function should read
 *
 * @chars_read: is a pointer to a variable that will hold
 *              the actual number of characters read by the function
 *
 */

void read_input(char **lineptr, size_t *n, ssize_t *chars_read)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		printf("#cisfun$ ");
	}
	*chars_read = getline(lineptr, n, stdin);
}
