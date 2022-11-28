#include <stdio.h>
#include <unistd.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */

extern char **environ;

int main(void)
{
    unsigned int i;

    i = 0;
    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }
    return (0);
}
