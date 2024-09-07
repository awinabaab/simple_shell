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

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] == NULL)
			status = 0;
		else if (is_num(args[1]) == 1 && (_atoi(args[1])) >= 0)
			status = _atoi(args[1]);
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


/**
 * non_interactive_exit - Controls non-interactive mode exit status
 * @args: Array of command and arguments
 *
 * Return: 2 if true, otherwise 0
 */
int non_interactive_exit(char **args, char *path, char *path_copy)
{
	int i = 0;

	if ((!isatty(STDIN_FILENO)) && (_strcmp(args[0], "exit") == 0))
	{
		while (args[i] != NULL)
			free(args[i++]);
		free(args);
		free_path(path, path_copy);
		return (2);
	}

	return (0);
}
