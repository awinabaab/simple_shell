#include "main.h"



/**
 * split_cmds - Separates multiple commands in a string
 *
 * @input: String of commands to be separated
 *
 * Return: Array of string cmds, NULL if input is NULL or memory alloc fails
 */
char **split_cmds(char *input)
{
	char **arr_of_cmds = NULL;
	int cmd_count = 0, j;
	char *input_copy = NULL, *token = NULL;

	if (input == NULL)
		return (NULL);

	input_copy = strdup(input);
	if (input_copy == NULL)
		return (NULL);

	arr_of_cmds = malloc(sizeof(char *) * (strlen(input) / 2 + 1));
	if (arr_of_cmds == NULL)
	{
		free(input_copy);
		return (NULL);
	}

	token = strtok(input_copy, ";");
	while (token != NULL)
	{
		arr_of_cmds[cmd_count] = strdup(token);
		if (arr_of_cmds[cmd_count] == NULL)
		{
			for (j = 0; j < cmd_count; j++)
				free(arr_of_cmds[j]);

			free(arr_of_cmds);
			free(input_copy);
			return (NULL);
		}
		cmd_count++;
		token = strtok(NULL, ";");
	}
	arr_of_cmds[cmd_count] = NULL;
	free(input_copy);
	return (arr_of_cmds);
}

