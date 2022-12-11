#include "main.h"

/**
 * fork_child - This function creates a child process using fork.
 *              It will attempt to execute the command specified by the
 *              first argument using execve.
 *
 * @lineptr: A pointer to the buffer that holds the input line
 * @args: Array of pointers to the individual arguemnts in the input line
 *
 * Return: 0 on success. If any of these fail, the function prints
 *         an error message and exit's the program.
 */

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
