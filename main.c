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
	const char *delim = " \t\n", *prompt = "($) ";
	int pcount = 1, i, interactive_mode = isatty(STDIN_FILENO);
	(void)ac;

	while (1)
	{
		if (interactive_mode)
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		input = getinput();
		if (input == NULL)
		{
			if (!interactive_mode)
				break;
			continue;
		}
		if (_strlen(input) == 1 && input[0] == '\n')
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
