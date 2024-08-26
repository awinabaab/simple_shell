#include "main.h"


/**
 * exit_shell - Handles the exit built-in command
 *
 * @args: Array of string arguments, with index 2 an optional exit status
 *
 * Return: The status
 */
int exit_shell(char **args)
{
	int status = 0;
	char *endptr;

	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1] == NULL)
			status = 0;
		else if ((strtol(args[1], &endptr, 10)) >= 0)
			status = strtol(args[1], &endptr, 10);
		else
			status = -1;
	}
	return (status);
}
