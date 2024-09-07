#include "main.h"

/**
 * find_cmd_in_path - Checks for command in path environment varible
 * @cmd: Command string
 * @args: Array of strings
 * @flname: File name
 * @pcount: Process count
 *
 * Return: Full path to @cmd or null if path is not a valid executable
 */

char *find_cmd_in_path(char *cmd, char **args, char *flname, int pcount)
{
	char *path = _getenv("PATH"), *path_copy = _strdup(path), *dir;
	static char full_path[1024];
	int i = 0;

	if (path == NULL || path_copy == NULL)
		return (NULL);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		if (non_interactive_exit(args, path, path_copy) == 2)
			exit(2);
		if (!isatty(STDIN_FILENO) && cmd[0] > 96 && cmd[0] < 123)
		{
			error_msg(args, path, path_copy, flname, pcount);
			exit(127);
		} else if (cmd[0] == '/' || isatty(STDIN_FILENO))
		{
			free_path(path, path_copy);
			return (cmd);
		} else if ((cmd[0] < 97 || cmd[0] > 122) && (!isatty(STDIN_FILENO)))
		{
			while (cmd[i++] != '\0')
			{
				if (cmd[i] > 96 && cmd[i] < 123)
				{
					free_path(path, path_copy);
					return (cmd + i);
				}
			}
			free_path(path, path_copy);
			return (NULL);
		} else if (validate_cmd(cmd, dir, full_path, sizeof(full_path)))
		{
			free_path(path, path_copy);
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}
	free_path(path, path_copy);
	return (NULL);
}


/**
 * free_path - Frees the path string
 * @path: Path
 * @path_copy: Copy of @path
 */

void free_path(char *path, char *path_copy)
{
	free(path);
	free(path_copy);
}


/**
 * validate_cmd - Validates if a command exits in directory
 * @dir: The directory to check
 * @cmd: The command to validate
 * @full_path: Buffer to store the full command if found
 * @size: Memory size of full_path
 *
 * Return: 1 if cmd is found, otherwise 0
 */
int validate_cmd(char *cmd, char *dir, char *full_path, size_t size)
{
	snprintf(full_path, size, "%s/%s", dir, cmd);
	if (access(full_path, X_OK) == 0)
	{
		return (1);
	}
	return (0);
}


/**
 * error_msg - stderr message
 * @args: Array of strings
 * @path: Environment path variable
 * @copy: Copy of path
 * @flname: File name
 * @pcount: process count
 */
void error_msg(char **args, char *path, char *copy, char *flname, int pcount)
{
	int i = 0;

	fprintf(stderr, "%s: %d: %s: not found\n", flname, pcount, args[0]);
	free_path(path, copy);
	while (args[i] != NULL)
		free(args[i++]);
	free(args);

}
