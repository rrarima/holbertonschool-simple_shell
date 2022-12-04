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

char *_getenv(const char *name);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
void print_env(void);
char *ll_path(char *);

#endif
