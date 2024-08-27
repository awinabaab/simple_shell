#include "main.h"

int is_num(char *str);

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
		else if (is_num(args[1]) == 1 && (strtol(args[1], &endptr, 10)) >= 0)
			status = strtol(args[1], &endptr, 10);
		else
			status = -1;
	}
	return (status);
}


/**
 * is_num - Checks if a string is numeric
 *
 * @str: The string to be checked
 *
 * Return: 1 if all characters are digit, else 0
 */
int is_num(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	while (*str)
	{
		if (!isdigit((unsigned char)*str))
			return (0);
		str++;
	}

	return (1);
}
