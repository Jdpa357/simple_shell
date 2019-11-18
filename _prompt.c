#include "shell.h"

/**
 * read_line_prompt - Function that sets a prompt "$ " and reads the line
 * checking for commands to execute
 *
 * Return: No return (Void function)
 */

char *read_line_prompt(void)
{

	char *line = NULL;
	size_t buff = 0;
	int length;

	write(STDOUT_FILENO, "$ ", 2);
	getline(&line, &buff, stdin);
	length = _strlen(line);
	line[length - 1] = '\0';

	return(line);

}
