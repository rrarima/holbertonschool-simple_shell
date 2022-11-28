#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int i;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	i = 0;
	while (i < 5)
	{
		if (fork() == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
			exit(0);
		}
		else
		{
			wait(NULL);
		}
		i = i + 1;
	}
	return (0);
}
