#include "shell.h"


/**
 * _strlen - Helper function to count the length of a string
 *
 * @s: Pointer to a string of chars to process by the function 
 * Return: The length of the string processed
 */

int _strlen(char *s)
{

	int count = 0;

	while (*(s + count) != '\0')
		count++;

	return (count);

}


/**
 * _strcmp - Compares two strings character by character.
 * Description: Compare two string character by character and return an integer
 * less than, equal to or greater than zero if the first string is less than,
 * to match or greater than the second string.
 * @s2: String to compare
 * @s1: String to compare
 *
 * Return: 0 if both strings are equal. The difference between the first
 * characters that do not match.
 */
int _strcmp(char *s1, char *s2)
{
	int len = 0;

	do {
		if (s1[len] - s2[len] != 0)
			return (s1[len] - s2[len]);
		len++;
	} while (s1[len] != '\0' || s2[len] != '\0');

	return (0);
}

