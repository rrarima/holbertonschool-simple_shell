#include "main.h"

/**
 * print_env - print all or part of environment
 *
 *
 */

void print_env(void)
{
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i = i + 1;
	}
}
