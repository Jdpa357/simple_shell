#include "shell.h"

/**
 * main - Function that executes the program
 *
 * Return: 0 always (Success);
 */

int main(void)
{
	char *c;

	c = read_line_prompt();
	printf("%s\n", c);
	return (0);

}
