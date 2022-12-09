#include "main.h"

int fork_child(char *lineptr, char *args[])
{
	pid_t child_pid;
	char *PATH = NULL;
	listpathdir_t *path;
	char **command_args = split_delim(lineptr, " \t\n\r");

	PATH = _getenv("PATH");
	path = ll_path(PATH);
	child_pid = fork();
	if (child_pid < 0)
	{
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		while (path != NULL)
		{
			char *command_path = strcat(strdup(path->dir), "/");
			command_path = strcat(command_path, command_args[0]);
			path = path->next;
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
