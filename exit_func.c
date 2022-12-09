#include "main.h"

void exit_func(char *lineptr)
{
	free(lineptr);
	exit(EXIT_SUCCESS);
}
