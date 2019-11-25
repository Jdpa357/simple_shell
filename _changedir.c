#include "shell.h"

/**
 * _dirch - Implements the directory change
 *
 * @cmm: Parameter of the directory to change to. if no directory is given, 
 * change to home directory
 * Return: Always 0 (Success)
 */

int _dirch(char **cmm)
{

	int stat = 0;
	char *dir = NULL;

	if (!cmm[1] || *cmm[1] == '~')
	{
		if (chdir("/home/vagrant") == 0)
			getcwd(dir, sizeof(dir));
		return (0);
	}
	else if (*cmm[1] == '-' && !cmm[1][1])
	{
		write(STDIN_FILENO, "home/vagrant\n", 15);
		if (chdir("/home/vagrant") == 0)
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
