#include "shell.h"

/**
 * getVarEnv - Get the value of an environment variable
 * @var: Variable to find
 * @env: Environment Variables
 *
 * Return: String with the content of the variable, or NULL if it does not
 * exist.
 */
char *getVarEnv(char *var, char **env)
{
	char *variable = NULL;
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		variable = findPattern(env[i], var);
		if (variable != NULL)
			return (variable + 1);
	}
	return (variable);
}


/**
 * findPattern - Find a pattern at the beginning of a string
 * Description: If the beginning of the string is equal to the pattern, return
 * a ponter next to the last character of the pattern (in the string)
 * @var: String to search
 * @sub: Pattern
 *
 * Return: Pointer to the next character after the pattern, or NULL if var does
 * not contain it.
 */
char *findPattern(char *var, char *sub)
{
	int len = 0;

	if (var == NULL || sub == NULL)
		return (NULL);

	for (; var[len] != '\0' && sub[len] != '\0'; len++)
		if (var[len] != sub[len])
			return (NULL);
	return (var + len);
}






