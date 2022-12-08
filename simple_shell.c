#include "main.h"

int main(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t chars_read = 0;
	char *args[1024];
	pid_t child_pid;
	int status;

	while (1)
	{
		read_input(&lineptr, &n, &chars_read);
		parse_input(lineptr, args, n, chars_read, &child_pid, &status);
	}

	free(lineptr);
	return 0;
}
