#include "main.h"

/**
 * update_pwd - Updates the current working directory
 *
 * @new_dir: new directory to upate t PWD to
 *
 * Return: Nothing
 */

void update_pwd(const char *new_dir)
{
	if (setenv("PWD", new_dir, 1) == -1)
		perror("setenv");
}

/**
 * get_old_pwd - Gets the previous working directory
 *
 * Return: The previous working directory
 */

const char *get_old_pwd(void)
{
	const char *old_pwd = _getenv("OLDPWD");

	if (old_pwd == NULL)
		return (NULL);

	return (old_pwd);
}

/**
 * change_dir - Changes into a new directory as specified
 *
 * @dir: Directory to change into
 *
 * Return: Nothing
 */

void change_dir(const char *dir)
{
	char current_dir[1024], new_dir[1024];
	const char *old_pwd;

	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("getcwd");
		return;
	}

	if (dir == NULL || _strcmp(dir, "~") == 0)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
			return;
	}

	if (_strcmp(dir, "-") == 0)
	{
		old_pwd = get_old_pwd();
		if (old_pwd == NULL)
			return;
		dir = old_pwd;
	}

	if (chdir(dir) != 0)
	{
		perror("chdir");
		return;
	}

	setenv("OLDPWD", current_dir, 1);
	if (getcwd(new_dir, sizeof(new_dir)) == NULL)
	{
		perror("getcwd");
		return;
	}
	update_pwd(new_dir);
}
