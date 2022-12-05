#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

/**
 * struct listpathdir_s - singly linked list
 * @dir: directory - (malloc'ed directory)
 * @next: point to next node
 *
 * Description: Longer description
 */
typedef struct listpathdir_s
{
	char *dir;
	struct listpathdir_s *next;
} listpathdir_t;

char *_getenv(const char *name);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
void print_env(void);
listpathdir_t *ll_path(char *PATH);
char **split_delim(char *, const char *);

#endif
