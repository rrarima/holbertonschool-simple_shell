#include "main.h"

int main(__attribute__((unused))int argc, char *argv[])
{
	size_t n = 0, i, num_of_tokens = 0;
	char *lineptr, *tmp, *token;
	pid_t child_pid;
	ssize_t chars_read = 0;
	int status;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			printf("#cisfun$ ");
		}
		chars_read = getline(&lineptr, &n, stdin);
		if (chars_read == -1)
		{
			free(lineptr);
			return (0);
		}

		tmp = malloc(sizeof(tmp) * chars_read);
		if (tmp == NULL)
		{
			return (-1);
			free(lineptr);
		}
		strcpy(tmp, lineptr);
		token = strtok(lineptr, " \t\n\r");
		i = 0;
		free(lineptr);
		while (i < n && token != NULL)
		{
			argv[i] = token;
			token = strtok(NULL, " \t\n\r");
			i = i + 1;
			num_of_tokens = num_of_tokens + 1;
			free(tmp);
			free(lineptr);
			lineptr = NULL;
			tmp = NULL;
		}
		if (strncmp(lineptr, "exit", 4) == 0)
		{
			free(lineptr);
			free(tmp);
			return (0);
			free(lineptr);
		}
		argv[i] = NULL;
		child_pid = fork();
		free(lineptr);
		if (child_pid < 0)
		{
			exit(0);
		}
		else if (child_pid == 0)
		{
			if (strcmp(lineptr, "env") == 0)
				{
					print_env();
					return (0);
				}
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("./shell");
			}
			exit(0);
		}
		wait(&status);
		free(tmp);
		free(lineptr);
	}
	free(lineptr);
	free(tmp);
	return (0);
}
