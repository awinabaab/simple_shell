#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "main.h"

/**
 * main - Prompt and await user input
 * @argv: Command line arguments
 * @argc: Size of @argv
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	char *lineptr = NULL;
	size_t n = 0;
	int get;

	(void)argc;
	while(1)
	{
		if (argv[1] && (strcmp(argv[1], "-i") == 0) &&
				(strcmp(argv[1], "-c") != 0))
			printf("($) ");
		else
			printf("$ ");
		get = getline(&lineptr, &n, stdin);
		if (get == -1)
		{
			printf("\n");
			free(lineptr);
			return (1);
		}
		else
		{
			printf("%s", lineptr);
			free(lineptr);
			lineptr = NULL;
		}
		printf("%d\n", get);
	}
	return (0);
}
