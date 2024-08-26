#include "main.h"

/**
 * execution - Executes a command using fork and execve
 *
 * @argv: The child command to be executed
 * @args: An array of child command arguments
 * @env: An array of environment string
 * @flname: The filname of the parent process
 * @pcount: child process count
 *
 * Return: 0 Always success
 */

int execution(char *argv, char **args, char **env, char *flname, int pcount)
{
	pid_t pid;
	struct stat st;
	int exit_stat = exit_shell(args), status;
	char *cmd = find_cmd_in_path(argv);

	if (strcmp(args[0], "exit") == 0)
	{
		if (exit_stat >= 0)
			exit(exit_stat);
		else
		{
			printf("%s: %d: %s: Illegal number: %s\n",
					flname, pcount, argv, args[1]);
			return (1);
		}
	} else if (strcmp(argv, "cd") == 0)
	{
		change_dir(args[1]);
		return (1);
	} else if (stat(cmd, &st) == -1)
	{
		printf("%s: %d: %s: not found\n", flname, pcount, argv);
		return (1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (1);
	} else if (pid == 0)
	{
		if (execve(cmd, args, env) == -1)
			return (1);
	} else if (wait(&status) == -1)
	{
		perror("wait");
		return (1);
	}
	return (0);
}
