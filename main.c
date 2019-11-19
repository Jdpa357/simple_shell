#include "shell.h"

/**
 * main - Function that executes the program
 *
 * Return: 0 always (Success);
 */

int main(void)
{
	char *c, *buff[90];
	ssize_t looper = 1;

	while (looper != EOF)
	{
		int i = 0, j = 0;

		c = read_line_prompt();
		buff[0] = strtok(c, " ");
		while (buff[i] != '\0')
		{
			i++;
			buff[i] = strtok(NULL, " ");
		}

		for (j = 0; j <= (i - 1); j++)
		{
			int k = 0;

			while (buff[j][k] != '\0')
			{
				write(1, &buff[j][k], 1);
				k++;
			}
			write(1, "\n", 1);
		}
		write(1, "\n", 1);
	}
	return (0);

}
