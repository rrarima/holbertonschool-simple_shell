#include "main.h"

int main(void)
{
	size_t n = 0, i, num_of_tokens = 0;
	char *lineptr = NULL, *token = NULL;
	pid_t child_pid;
	ssize_t chars_read = 0;
	int status;
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
			i = 0;
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
			child_pid = fork();
			if (child_pid < 0)
			{
				exit(EXIT_FAILURE);
			}
			else if (child_pid == 0)
			{
				if (strcmp(lineptr, "env") == 0)
				{
					print_env();
					return (0);
				}
				if (execve(args[0], args, environ) == -1)
				{
					free(lineptr);
					perror("./shell");
				}
				exit(EXIT_SUCCESS);
			}
			wait(&status);
		}
	}
	free(lineptr);
	return (0);
}
