#include "main.h"

/**
 * find_cmd_in_path - Checks for command in path environment varible
 * @cmd: Command string
 *
 * Return: Full path to @cmd or null if path is not a valid executable
 */

char *find_cmd_in_path(char *cmd)
{
	char *path, *path_copy, *dir;
	static char full_path[1024];

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);
	path_copy = _strdup(path);
	if (path_copy == NULL)
		return (NULL);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		if (cmd[0] == '/')
		{
			free_path(path, path_copy);
			return (cmd);
		} else if (cmd[0] == '.' && cmd[1] == '/')
		{
			free_path(path, path_copy);
			return (cmd + 2);
		} else if (cmd[0] == '.' && cmd[1] == '.' && cmd[2] == '/' &&
			(cmd[3] > 96 && cmd[3] < 123))
		{
			free_path(path, path_copy);
			return (cmd);
		} else if (cmd[0] == '.' && cmd[1] == '.' && cmd[2] == '/')
		{
			free_path(path, path_copy);
			return (cmd + 3);
		}
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, cmd);
		if (access(full_path, X_OK) == 0)
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
