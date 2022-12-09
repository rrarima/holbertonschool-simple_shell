#include "main.h"

int main(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t chars_read = 0;
	char *args[1024];
	int status;

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
		parse_input(lineptr, args, n, chars_read);
		if(WIFEXITED(status))
		{
			printf("exit status of child=%d\n",WEXITSTATUS(status));
		}
	}
	free(lineptr);
	return (0);
}

void parse_input(char *lineptr, char *args[], size_t n, ssize_t chars_read)
{
	size_t i;
	char *token = strtok(lineptr, " \t\n\r");

	if (lineptr[chars_read - 1] == '\n')
	{
		lineptr[chars_read - 1] = '\0';
	}
	if (token != NULL)
	{
		i = 0;
		while (i < n && token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " \t\n\r");
			i = i + 1;
		}
		if (strncmp(lineptr, "exit", 4) == 0)
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		args[i] = NULL;
		fork_child(lineptr, args);
	}
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
