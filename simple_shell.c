#include "main.h"

int main(__attribute__((unused))int argc, char *argv[])
{
	size_t n = 0, i;
	char *lineptr = NULL;
	char *token;
	pid_t child_pid;

	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&lineptr, &n, stdin) == -1)
		{
			break;
		}
		token = strtok(lineptr, " \t\n\r");
		i = 0;
		while (i < n && token != NULL)
		{
			argv[i] = token;
			token = strtok(NULL, " \t\n\r");
			i = i + 1;
		}
		if (strncmp(argv[0], "exit", 4) == 0)
		{
			return (0);
		}
		argv[i] = NULL;
		child_pid = fork();
		if (child_pid == 0)
		{
			if (strcmp(argv[0], "env") == 0)
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
		else
		{
			waitpid(child_pid, NULL, 0);
		}
	}
	return (0);
}
