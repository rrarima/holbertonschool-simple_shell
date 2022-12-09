#include "main.h"

int fork_child(char *lineptr, char *args[], int *exit_code)
{
	pid_t child_pid;
	int status;

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
		if (execve(args[0], args, environ) == -1)
		{
			perror("./shell");
		}
	}
	else
	{
		wait(&status);
		if(WIFEXITED(status))
		{
			*exit_code = WEXITSTATUS(status);
		}
	}
	return (0);
}
