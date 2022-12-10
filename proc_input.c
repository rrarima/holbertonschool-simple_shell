#include "main.h"

void process_input(char *lineptr, size_t n, int *exit_code)
{
	listpathdir_t *head;
	char *path;
	char *command_path;
	ssize_t chars_read = 0;
	char *args[1024];

	chars_read = getline(&lineptr, &n, stdin);
	if (chars_read == -1)
	{
		return;
	}
	if (parse_input(lineptr, args, chars_read, exit_code) == 0)
	{
		if (*args[0] == '/')
		{
			if (access(args[0], F_OK | X_OK) == 0)
			{
				fork_child(lineptr, args, exit_code);
			}
		}
	else
	{
		path = _getenv("PATH");
		head = ll_path(path);
		printf("This is arg[0] %s\n", args[0]);
		command_path = access_check(head, args[0]);
		printf("This is the command path: %s\n", command_path);
		if (command_path == args[0])
		{
			if (access(args[0], F_OK | X_OK) == 0)
			{
				fork_child(lineptr, args, exit_code);
			}
		}
		else
		{
			args[0] = command_path;
			fork_child(lineptr, args, exit_code);
		}
	}
    }
}
