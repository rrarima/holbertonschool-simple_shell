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
void split_delim(char *s, const char *delim, char *whole_path[]);
void exit_func(char *lineptr);
int parse_input(char *lineptr, char *args[], ssize_t chars_read, int *exit_code);
void read_input(char **lineptr, size_t *n, ssize_t *chars_read);
int fork_child(char *lineptr, char *args[], int *exit_code);
char *access_check(listpathdir_t *head, char *argv_0);
#endif
