#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * main - Entry point for program execution
 *
 * @ac: argument count
 * @av: array of arguments
 * @env: array of environment argument string
 * return: 0
 */
int main(int ac, char **av, char **env)
{
	char **strarr = NULL;
	char *input = NULL;
	const char *delim = " \t\n";
	int pcount = 1; int exec_stat;
	(void)ac;

	while (1)
	{
		printf("simple_shell$ ");

		input = getinput();
		if (input == NULL)
		{
			free(input);
		}
		strarr = inptstr_tok(input, delim);
		if (strarr == NULL)
		{
			free(input);
			continue;
		}
		exec_stat = execution(strarr[0], strarr, env, av[0], pcount);
		if (exec_stat == -1)
		{
			free(input);
			continue;
		}

		free(input);
		free(strarr);
		pcount++;
	}
	return (0);
}
