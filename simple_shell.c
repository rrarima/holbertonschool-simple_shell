#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

int main(__attribute__((unused))int ac, char **av, char **env)
{
	size_t n = 20;
	size_t i;
	char *lineptr;
	char *token;
	pid_t child_pid;

	lineptr = NULL;
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
			av[i] = token;
			token = strtok(NULL, " \t\n\r");
			i = i + 1;
		}
		av[i] = NULL;
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(av[0], av, env) == -1)
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
