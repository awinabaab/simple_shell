#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * prepare_token_array - counts tokens and allocates memory for the token array
 *
 * @input: input string
 * @delim: delimiter string
 * Return: pointer to allocated token array or NULL on failure
 */
char **prepare_token_array(char *input, char *delim)
{
	int count = 0;
	char **argv;
	char *input_copy = strdup(input);
	char *token;

	if (input_copy == NULL)
	{
		perror("strdup");
		return (NULL);
	}

	token = strtok(input_copy, delim);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}

	argv = malloc(sizeof(char *) * (count + 1));
	if (argv == NULL)
	{
		perror("malloc");
		free(input_copy);
		return (NULL);
	}

	free(input_copy);
	return (argv);
}


/**
 * inptstr_tok - tokenizes a string and puts it into an array
 *
 * @input: input string
 * @delim: delimiter string
 * Return: an array of strings (tokens)
 */
char **inptstr_tok(char *input, char *delim)
{
	char **argv;
	char *token;
	int i = 0;

	argv = prepare_token_array(input, delim);
	if (argv == NULL)
	{
		return (NULL);
	}

	token = strtok(input, delim);
	while (token != NULL)
	{
		argv[i] = strdup(token);
		if (argv[i] == NULL)
		{
			perror("strdup");

			while (i > 0)
			{
				free(argv[--i]);
			}
			free(argv);
			return (NULL);
		}
		i++;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	return (argv);
}


/*char **inptstr_tok(char *input, char *delim)
{
	int size = 1;
	char **tokens;
	char *tok;
	int i;

	tokens = malloc(sizeof(char *) * size);
	tok = strtok(input, delim);
	while (tok != NULL)
	{
		i = size - 1;
		size++;
		tokens = realloc(tokens, size * sizeof(char *));
		tokens[i] = malloc(strlen(tok) * sizeof(char));
		strcpy(tokens[i], tok);
		tok = strtok(NULL, delim);
	}
	tokens[size - 1] = NULL;
	return (tokens);
}*/
