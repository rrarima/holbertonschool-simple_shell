#include <stdio.h>

int main(__attribute__((unused))int ac, char **av)
{
	size_t n = 100;
	printf("$ ");
	getline(av, &n, stdin);
	printf("%s", *av);
	return (0);
}
