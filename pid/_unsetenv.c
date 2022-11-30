#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char **environ;
int _unsetenv(const char *name)
{
	char **ep, **sp;
	size_t len;

	len = strlen(name);
	ep = environ;
	while (*ep != NULL)
	{
		if (strncmp(*ep, name, len)==0 && (*ep)[len] == '=')
		{
			sp = ep;
			while (*sp != NULL)
			{
				*sp = *(sp+1);
				sp = sp + 1;
			}
		}
		else
		{
			ep = ep + 1;
		}
	}
	return 0;
}

int main()
{
	char *home = getenv("HOME");
	unsetenv(home);
	return 0;
}
