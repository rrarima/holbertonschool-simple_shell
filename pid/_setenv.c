#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

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

int main()
{
	const char *home;
	home = getenv("HOME");
	printf("Original HOME=%s\n", home);
	_setenv("HOME", "wheretheheartis", 1);
	const char *newhome;
	newhome = getenv("HOME");
	printf("New HOME=%s\n", newhome);
	return (0);
}
