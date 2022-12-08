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
		if (strncmp(lineptr, "exit", 4) == 0)
		{
		free(lineptr);
		exit(EXIT_SUCCESS);
		}
		args[i] = NULL;
		*child_pid = fork();
		if (*child_pid < 0)
		{
		exit(EXIT_FAILURE);
		}
		else if (*child_pid == 0)
		{
			if (strcmp(lineptr, "env") == 0)
			{
				print_env();
				free(lineptr);
			}
			if (execve(args[0], args, environ) == -1)
			{
				free(lineptr);
				perror("./shell");
			}
			exit(EXIT_SUCCESS);
		}
		wait(status);
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
