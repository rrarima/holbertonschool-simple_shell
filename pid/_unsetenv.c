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

char *_getenv(const char *name)
{
	int i, j;
	int status;

	i = 0;
	while (environ[i] != NULL)
	{
		status = 1;
		j = 0;
		while (environ[i][j] != '=')
		{
			if (name[j] != environ[i][j])
			{
				status = 0;
				break;
			}
			j = j + 1;
		}
		if (status)
		{
			return (&environ[i][j + 1]);
		}
		i = i + 1;
	}
	return (NULL);
}

int _setenv(const char *name, const char *value, int overwrite)
{
	char *name_copy;
	unsigned int i;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL || value == NULL)
	{
		return (-1);
	}
	if (getenv(name) != NULL && overwrite == 0)
	{
		return (0);
	}
	name_copy = malloc(strlen(name) + strlen(value) + 2);
	if (name_copy == NULL)
	{
		return (-1);
	}
	strcpy(name_copy, name);
	strcat(name_copy, "=");
	strcat(name_copy, value);
	return (putenv(name_copy) != 0) ? -1 : 0;
}

/*
int main(void)
{
	char *path = _getenv("PATH");

	printf("PATH: %s\n", path);
	_setenv("FOO", "bar", 1);
	printf("FOO: %s\n", _getenv("FOO"));
	_unsetenv("FOO");
	printf("FOO: %s\n", _getenv("FOO"));
	return (0);
	}*/
