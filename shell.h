#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/** Path structure */
typedef struct path_t
{
	char *dir;
	struct path_t *next;
} path_l;

/** String helpers */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);

/** Processing functions */
char *read_line_prompt(void);

#endif
