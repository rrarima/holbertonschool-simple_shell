#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

char **split (char *str);

int main(int ac, char **av, char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n_char;
	char **command;

	while(1)
	{
		printf("$ ");

		n_char = getline(&line, &len, stdin);
		line[n_char - 1] = '\0';
		command = split(line);
		if (fork() == 0)
		{
			execve(command[0], command, env);
		}
		else
		{
			wait(NULL);
			free(line);
			line = NULL;
		}
	}
	return (n_char);
}
