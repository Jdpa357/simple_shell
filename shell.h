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

/** Signal Handler */
void exception_handler(int sig_num);

/** String helpers */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);

/** Processing functions */
char *read_line_prompt(void);
int _dirch(char **cmm);

/** executor */
int _exec(char **args, char **env);


#endif
