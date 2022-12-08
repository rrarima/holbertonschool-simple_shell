#include "main.h"

void read_input(char **lineptr, size_t *n, ssize_t *chars_read)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		printf("#cisfun$ ");
	}
	*chars_read = getline(lineptr, n, stdin);
}
