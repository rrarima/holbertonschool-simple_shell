#include "main.h"

char *access_check(listpathdir_t *head, char *argv_0)
{
	listpathdir_t *node = NULL;
	char *command;
	int path_len;
	int command_len;

	node = head;
	command_len = strlen(argv_0);
	while (node != NULL)
	{
		path_len = strlen(node->dir);
		command = malloc(sizeof(*command) * (command_len + path_len + 2));
		if (command == NULL)
		{
			return (NULL);
		}
		strcpy(command, node->dir);
		strcat(command, "/");
		strcat(command, argv_0);
		if (access(command, F_OK | X_OK) == 0)
		{
			return (command);
		}
		else if (access(command, F_OK | X_OK) == -1)
		{
			exit(127);
		}
		free(command);
       		node = node->next;
	}
	return (argv_0);
}
