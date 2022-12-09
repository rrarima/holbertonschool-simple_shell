#include "main.h"

/**
 * _getenv - get an environment variable
 * @name: takes the string 'name' as an argument and searches
 *        environ global variable for an
 *        enviroment variable with the given name
 *
 * Return: NULL if variable is not found.
 */

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
