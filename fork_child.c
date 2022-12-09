#include "main.h"

int fork_child(char *lineptr, char *args[])
{
	pid_t child_pid;

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
			free(lineptr);
			return (0);
		}
		if (strcmp(args[0], "ls") == 0)
		{
			char *ls_args[] = {"ls", NULL};
			if (execve("/bin/ls", ls_args, environ) == -1)
			{
				free(lineptr);
				perror("./shell");
			}
		}
		if (execve(args[0], args, environ) == -1)
		{
			free(lineptr);
			perror("./shell");
		}
		exit(EXIT_SUCCESS);
	}
	wait(&child_pid);
	return (0);
}
