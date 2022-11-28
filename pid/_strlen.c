#include "main.h"

/**
* _strlen - return length of string
* @s: return len of string
* Return: value on strlen
**/

int _strlen(const char *s)
{
	int len = 0;

	while (s[len]) != '\0')
	{
		len++;
	}

	return (len);
}
