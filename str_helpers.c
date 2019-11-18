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
