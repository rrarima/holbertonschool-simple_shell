#include "main.h"

int main(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t chars_read = 0;
	char *args[1024];

	while (1)
	{
		read_input(&lineptr, &n, &chars_read);
		if(chars_read == -1)
		{
			break;
		}
		parse_input(lineptr, args, n, chars_read);
	}

	free(lineptr);
	return 0;
}
