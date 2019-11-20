#include "shell.h"

/**
 * _exec - Executes a program passed to the simple shell
 *
 * @args: A pointer to a pointer of command line arguments passed to the simple
 * shell
 * @env: Environment Variables
 * Return: 0 Always (Success)
 */

int _exec(char **args, char **env)
{

	pid_t child_id;
	int status;

	child_id = fork();
	if (child_id == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			close(STDIN_FILENO);
			perror("Error: Command not found");
		}
	}
	else if (child_id == -1)
	{
		perror("Error: Child process failed");
		exit(99);
	}
	else
	{
		do {
			waitpid(child_id, &status, WUNTRACED);
		} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}
	return (0);
}
