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
	char *path;

	path = findPath(args[0], env);
	if (path == NULL)
	{
		perror(args[0]);
		return (0);
	}
	child_id = fork();
	if (child_id == 0)
	{
		if (path != NULL)
			if (execve(path, args, env) == -1)
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


/**
 * findPath - Return the path of an executable file
 * @exe: Name of the executable
 * @env: Environment Variables
 *
 * Return: String with the complete path of the executable, or NULL if does
 * not exist.
 */
char *findPath(char *exe, char **env)
{
	char *path, *buff = "\0", *tmp;
	struct stat *aux;

	tmp = malloc(1024 * sizeof(char));
	aux = malloc(sizeof(struct stat));
	if (stat(exe, aux) == 0)
	{
		free(tmp);
		free(aux);
		return (exe);
	}

	path = getVarEnv("PATH", env);
	path = _strdup(path);
	buff = strtok(path, ":");
	_strcpy(tmp, buff);
	while (buff != NULL)
	{
		_strcat(tmp, "/\0");
		_strcat(tmp, exe);

		if (stat(tmp, aux) == 0)
		{
			free(path);
			free(aux);
			_strcpy(buff, tmp);
			free(tmp);
			return (buff);
		}

		buff = strtok(NULL, ":");
		_strcpy(tmp, buff);
	}

	free(path);
	free(tmp);
	free(aux);
	return (NULL);
}
