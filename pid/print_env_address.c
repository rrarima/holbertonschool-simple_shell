#include <stdio.h>
#include <unistd.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */

extern char **environ;

int main(int ac, char **av, char **env)
{
    printf("\n");
    printf("This is the address for [global] variable environ: %p\n", environ);
    printf("------------------------------------\n");
    printf("This is the address for [local] variable env: %p\n", env);
    printf("\n");
    return (0);
}
