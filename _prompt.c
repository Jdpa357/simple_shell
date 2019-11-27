#include "shell.h"

/**
 * read_line_prompt - Function that sets a prompt "$ " and reads the line
 * checking for commands to execute. If running in non-interactive mode, it
 * does not print.
 *
 * Return: No return (Void function)
 */

char *read_line_prompt(void)
{

	char *line = NULL;
	size_t buff = 0;
	int length, readed, mode = 1;

	if (isatty(STDIN_FILENO) == 0)
		mode = 0;
	do  {
		if (mode == 1)
			write(STDOUT_FILENO, "$ ", 2);
		readed = getline(&line, &buff, stdin);
		if (readed < 0)
		{
			exit(0);
		}
		length = _strlen(line);
		line[length - 1] = '\0';
	} while (line == NULL || *line == '\0');
	return (line);
}
