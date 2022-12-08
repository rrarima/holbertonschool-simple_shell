#include "main.h"

int main(void)
{
	size_t n = 0, i;
	char *lineptr = NULL, *token = NULL;
	ssize_t chars_read = 0;
	char *args[64];

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			printf("#cisfun$ ");
		}
		chars_read = getline(&lineptr, &n, stdin);
		if (chars_read == -1)
		{
			break;
		}
		if (lineptr[chars_read - 1] == '\n')
		{
			lineptr[chars_read - 1] = '\0';
		}
		token = strtok(lineptr, " \t\n\r");
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
				exit_func(lineptr);
			}
			args[i] = NULL;
			fork_child(lineptr, args);
		}
	}
	free(lineptr);
	return (0);
}
