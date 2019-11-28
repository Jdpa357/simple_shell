#include "shell.h"

/**
 * _dirch - Implements the directory change
 *
 * @cmm: Parameter of the directory to change to. if no directory is given,
 * change to home directory
 * Return: Always 0 (Success)
 */

int _dirch(char **cmm, char **env)
{

	int stat = 0, len = 0;
	char *dir = NULL;
	char *home;

	if (!cmm[1] || *cmm[1] == '~')
	{
		home = getVarEnv("HOME", env);
		if (chdir(home) == 0)
			getcwd(dir, sizeof(dir));
		return (0);
	}
	else if (*cmm[1] == '-' && !cmm[1][1])
	{
		home = getVarEnv("OLDPWD", env);
		len = _strlen(home);
		write(STDIN_FILENO, home, len);
		write(STDIN_FILENO, "\n", 1);
		if (chdir(home) == 0)
			getcwd(dir, sizeof(dir));
		return (0);
	}
	else
	{
		stat = chdir(cmm[1]);
		if (stat == -1)
			perror("cd");
		return (0);
	}

}
