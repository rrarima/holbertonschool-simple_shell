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
	size_t j;
	char *lineptr;
	char *token;

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
		if (fork() == 0)
		{
			if (execve(av[0], av, env) == -1)
			{
				perror("./shell");
			}
			exit(0);
		}
		else
		{
			wait(NULL);
		}
		j = 0;
		while (env[j] != NULL)
		{
			printf("\n%s", env[j]);
			j = j + 1;
		}
		printf("\n");
	}
	return (0);
}