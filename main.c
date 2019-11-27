#include "shell.h"
/*void handler(int sig);*/
/**
 * main - Function that executes the program
 * @ac: Number of parameters of the program
 * @av: Arguments
 * @env: Environment Variables
 *
 * Return: 0 always (Success);
 */

int main(int ac __attribute__((unused)), char **av __attribute__((unused)),
		char **env)
{
	char *c, *buff[90];
	ssize_t looper = 1;

	signal(SIGINT, exception_handler);

	while (looper != EOF)
	{
		int i = 0;

		c = read_line_prompt();

		buff[0] = strtok(c, " ");
		while (buff[i] != '\0')
		{
			i++;
			buff[i] = strtok(NULL, " ");
		}

		if (!_strcmp(buff[0], "exit"))
			exit(0);
		else if (!_strcmp(buff[0], "cd"))
		{
			_dirch(buff);
		}
		else
		{
			_exec(buff, env);
		}
		free(c);
	}
	return (0);
}
