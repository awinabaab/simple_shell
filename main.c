#include "main.h"



/**
 * prompt - prints the prompt on the stdout to take in input
 *
 * Return: Nothing
 */
void prompt(void)
{
	int interactive_mode = isatty(STDIN_FILENO);
	char *prompt = "($) ";

	if (interactive_mode == 1)
		write(STDOUT_FILENO, prompt, _strlen(prompt));
}



/**
 * main - Entry point for program execution
 * @ac: argument count
 * @av: array of arguments
 * Return: 0
 */
int main(int ac, char **av)
{
	char **strarr = NULL;
	char *input = NULL;
	const char *delim = " \t\n";
	int pcount = 1, j, i;
	(void)ac;

	while (1)
	{
		prompt();
		input = getinput();
		if ((_strlen(input) == 1 && input[0] == '\n') || input == NULL)
		{
			free(input);
			continue;
		}
		strarr = inputstr_tok(input, delim);
		if (strarr == NULL)
		{
			free(input);
			continue;
		}
		if (strarr != NULL)
		{
			j = execution(strarr, av[0], pcount);
		}
		i = 0;
		while (strarr[i] != NULL)
			free(strarr[i++]);
		free(strarr);
		pcount++;
	}
	return (j);
}
