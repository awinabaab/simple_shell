#include "main.h"



/**
 * getinput - gets input from keyboard
 *
 * Return: input string
 */
char *getinput(void)
{
	char *input = NULL;
	size_t input_len = 0;
	ssize_t read;

	read = getline(&input, &input_len, stdin);

	if (read == -1)
	{
		free(input);
		if (isatty(STDIN_FILENO))
		{
			_putchar('\n');
		}
		exit(0);
	}

	return (input);
}
