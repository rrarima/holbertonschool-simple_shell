#include "main.h"

int parse_input(char *lineptr, char *args[], ssize_t chars_read, int *exit_code)
{
	size_t i;
	char *token;

	if (lineptr[chars_read - 1] == '\n')
	{
		lineptr[chars_read - 1] = '\0';
	}
	token = strtok(lineptr, " \t\n\r");
	if (token == NULL)
	{
		return (1);
	}
	i = 0;
	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " \t\n\r");
		i = i + 1;
	}
	if (strncmp(lineptr, "exit", 4) == 0)
	{
		free(lineptr);
		exit(*exit_code);
	}
	args[i] = NULL;
	return (0);
}
