#include "main.h"

int main(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	int exit_code = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			printf("#cisfun$ ");
		}
		process_input(lineptr, n, &exit_code);
	}
	free(lineptr);
	return (0);
}
