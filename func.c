#include "main.h"

void parse_input(char *lineptr, char *args[], size_t n, ssize_t chars_read, pid_t *child_pid, int *status)
{
	char *token = strtok(lineptr, " \t\n\r");

	if (chars_read == -1)
	{
		return;
	}
	if (lineptr[chars_read - 1] == '\n')
	{
		lineptr[chars_read - 1] = '\0';
	}
	if (token != NULL)
	{
		size_t i = 0, num_of_tokens = 0;
		while (i < n && token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " \t\n\r");
			i = i + 1;
			num_of_tokens = num_of_tokens + 1;
		}
		if (strncmp(lineptr, "exit", 4) != 0 && strcmp(lineptr, "env") != 0)
		{
			printf("Invalid built-in command: %s\n", lineptr);
			free(lineptr);
			exit(2);
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

void read_input(char **lineptr, size_t *n, ssize_t *chars_read)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		printf("#cisfun$ ");
	}
	*chars_read = getline(lineptr, n, stdin);
}

void print_env(void)
{
    unsigned int i = 0;

    while (environ[i] != NULL)
    {
	    printf("%s\n", environ[i]);
	    i = i + 1;
    }
}
