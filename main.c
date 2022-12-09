#include "main.h"

int main(void)
{
	listpathdir_t *head;
	char *lineptr = NULL;
	char *path;
	char *command_path;
	size_t n = 0;
	ssize_t chars_read = 0;
	char *args[1024];
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
				printf("This is arg[0] %s\n", args[0]);
				command_path = access_check(head, args[0]);
				printf("This is the command path: %s\n", command_path);
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

int parse_input(char *lineptr, char *args[], ssize_t chars_read, int *exit_code)
{
	size_t i;
	char *token;

	if (lineptr[chars_read - 1] == '\n')
	{
		lineptr[chars_read - 1] = '\0';
	}
	token = strtok(lineptr, " \t\n\r");
	if (token == NULL)
	{
		return (1);
	}
	i = 0;
	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " \t\n\r");
		i = i + 1;
	}
	if (strncmp(lineptr, "exit", 4) == 0)
	{
		free(lineptr);
		exit(*exit_code);
	}
	args[i] = NULL;
	return (0);
}

void print_env(void)
{
    unsigned int i = 0;

    while (environ[i] != NULL)
    {
	    printf("%s\n", environ[i]);
	    i = i + 1;
    }
}

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
		printf("This is args[0] %s\n", args[0]);
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
			printf("exit status of child=%d\n",WEXITSTATUS(status));
		}
	}
	return (0);
}
