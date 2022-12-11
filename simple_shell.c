#include "main.h"

int main(void)
{
	listpathdir_t *head;
	char *lineptr = NULL, *path, *command_path, *args[1024];
	size_t n = 0;
	ssize_t chars_read = 0;
	int exit_code = 0;

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
		if (parse_input(lineptr, args, chars_read, &exit_code) == 0)
		{
			if (*args[0] == '/')
			{
				if (access(args[0], F_OK | X_OK) == 0)
				{
					fork_child(lineptr, args, &exit_code);
				}
			}
			else
			{
				path = _getenv("PATH");
				head = ll_path(path);
				command_path = access_check(head, args[0]);
				if (command_path == args[0])
				{
					if (access(args[0], F_OK | X_OK) == 0)
					{
						fork_child(lineptr, args, &exit_code);
					}
				}
				else
				{
					args[0] = command_path;
					fork_child(lineptr, args, &exit_code);
				}
			}
		}
	}
	free(lineptr);
	return (0);
}
