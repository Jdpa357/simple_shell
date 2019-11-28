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

	if (s == NULL)
		return (0);
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

	if (s1 == NULL || s2 == NULL)
		return (-1);
	do {
		if (s1[len] - s2[len] != 0)
			return (s1[len] - s2[len]);
		len++;
	} while (s1[len] != '\0' || s2[len] != '\0');

	return (0);
}


/**
 * _strdup - Duplicate a string
 * Description: Returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter. This can be freed whith
 * free().
 * @str: pointer to the string to duplicate
 *
 * Return: A pointer to the newly allocated string, or NULL if it fails
 */
char *_strdup(char *str)
{
	int i, size = 0;
	char *ptr;

	if (str == NULL)
		return (NULL);

	while (str[size] != '\0')
		size++;
	ptr = malloc(sizeof(char) * size + 1);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		ptr[i] = str[i];
	ptr[i] = '\0';

	return (ptr);
}


/**
 * _strcat - This function appends the src string to the dest string,
 * overwriting the terminating null byte (\0) at the end of dest, and then adds
 * a terminating null byte.
 * @dest: First part of the string.
 * @src: Second part of the string, to append to dest.
 *
 * Return: Pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	int len = 0, cnt = 0;

	while (dest[len] != '\0')
		len++;

	do {
		dest[len] = src[cnt];
		len++;
		cnt++;
	} while (src[cnt] != '\0');
	dest[len] = '\0';

	return (dest);
}


/**
 * _strcpy - Copies the string pointed to by src, including the terminating
 * null byte (\0), to the buffer pointed to by dest.
 * @dest: Destiny buffer.
 * @src: Pointer to origin string.
 * Return: the pointer to dest.
 */

char *_strcpy(char *dest, char *src)
{
	int count;

	if (src == NULL)
	{
		dest = NULL;
		return (dest);
	}
	for (count = 0; src[count] != '\0'; count++)
		dest[count] = src[count];

	dest[count] = '\0';
	dest[count + 1] = '\0';

	return (dest);
}
