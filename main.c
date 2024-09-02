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
 * @env: array of environment argument string
 * Return: 0
 */
int main(int ac, char **av)
{
	char **strarr = NULL;
	char *input = NULL;
	const char *delim = " \t\n";
	int pcount = 1, j;
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
			free(strarr);
			continue;
		}
		if (strarr != NULL)
		{
			j = execution(strarr, av[0], pcount);
		}
		free(strarr);
		pcount++;
	}
	return (j);
}
