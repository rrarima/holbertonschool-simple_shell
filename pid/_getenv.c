#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

char *_getenv(const char *name)
{
	int i = 0;
	int len = strlen(name);

	while (environ[i] != NULL)
	{
		if (strncmp(name, environ[i], len) ==0)
		{
			return (environ[i]);
		}
		i++;
	}
	return (NULL);
}

int main ()
{
	printf("HOME:%s\n", _getenv("HOME"));
	return (0);
}
