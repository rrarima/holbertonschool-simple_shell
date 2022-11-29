#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *path = getenv("PATH");
	int length = strlen(path) -1;
	int i;

	i = 0;
	while (i <= length)
	{
		if (path[i] == ':')
		{
			path[i] = '\n';
		}
		printf("%c",path[i]);
		i = i + 1;
	}
	printf("\n");
	return (0);
}
