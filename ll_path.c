#include "main.h"

listpathdir_t *ll_path(char *PATH)
{
	int i = 0;
	char *whole_path[1024];
	listpathdir_t *new, *head = NULL;

	split_delim(PATH, ":", whole_path);
	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		perror("failed to malloc");
		return (NULL);
	}
	while (whole_path[i] != NULL)
	{
		new->dir = strdup(whole_path[i]);
		new->next = head;
		head = new;
		i = i + 1;
	}
	free(new);
	return (head);
}


void split_delim(char *s, const char *delim, char *whole_path[])
{
	char *s1 = NULL, *piece = NULL, *ptr = NULL;
	int i = 0, j = 0;

	while (ptr == s && (ptr = strstr(ptr, delim)))
	{
		i = i + 1;
		ptr = ptr + 1;
	}
	s1 = strdup(s);
	piece = strtok(s1, delim);
	while (piece != NULL)
	{
		whole_path[j] = piece;
		piece = strtok(NULL, delim);
		j = j + 1;
	}
	whole_path[j] = NULL;
}
