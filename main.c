#include "main.h"

/**
 * main - Entry point for program execution
 *
 * @ac: argument count
 * @av: array of arguments
 * @env: array of environment argument string
 *
 * Return: 0
 */

int main(int ac, char **av, char **env)
{
	char **strarr = NULL, **strarrs = NULL;
	char *input = NULL;
	const char *delim = " \t\n";
	int pcount = 1, i;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");

		input = getinput();
		if (input == NULL)
			continue;

		strarrs = split_cmds(input);
		if (strarrs == NULL)
		{
			free(input);
			continue;
		}
		i = 0;
		while (strarrs[i] != NULL)
		{
			strarr = inputstr_tok(strarrs[i++], delim);
			if (strarr != NULL)
			{
				execution(strarr[0], strarr, env, av[0], pcount);
				free(strarr);
			}
		}
		free(input);
		free(strarrs);
		pcount++;
	}
	free(input);
	free(strarrs);
	return (0);
}
