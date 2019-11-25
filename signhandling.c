#include "shell.h"

/**
 * exception_handler - Function to control the Ctrl-C signal
 *
 * @sig_num: The integer of the signal given to the command
 * Return: No return (Void function)
 */

void exception_handler(int sig_num)
{
	(void)sig_num;
	write(1, "\n", 1);
	write(1, "$ ", 2);
}

