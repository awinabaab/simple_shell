#include "main.h"

/**
 * main - Entry point for program execution
 *
 * Return: 0
 */

int main(void)
{
	char **strarr = NULL, **strarrs = NULL;
	char *input = NULL;
	const char *delim = " \t\n";
	int pcount = 1, i;

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
				execution(strarr[0], strarr, environ, strarr[1], pcount);
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
