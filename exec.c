#include "main.h"

/**
 * execution - Executes a command using fork and execve
 *
 * @args: An array of child command arguments
 * @flname: The filname of the parent process
 * @pcount: child process count
 *
 * Return: 0 Always success
 */

int execution(char **args, char *flname, int pcount)
{
	pid_t pid;
	struct stat *st;
	int status, exit_stat = exit_shell(args);
	char *cmd = find_cmd_in_path(args[0], args, flname, pcount);

	st = malloc(sizeof(struct stat));
	if (!st || !args)
		return (0);
	if (strcmp(args[0], "exit") == 0)
	{
		free(st);
		exit_st(exit_stat, args, flname, pcount);
		exit(0);
	}
	else if (stat(cmd, st) == -1)
	{
		printf("%s: %d: %s: not found\n", flname, pcount, args[0]);
		free(st);
		return (0);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		free(st);
		return (0);
	} else if (pid == 0)
	{
		if (execve(cmd, args, environ) == -1)
			return (0);
	}
	else
		if (wait(&status) == -1)
		{
			perror("wait");
			return (0);
		}
	free(st);
	return (0);
}

/**
 * free_args - Frees a double pointer @args
 * @args: Double pointer to be freed
 */
void free_args(char **args)
{
	int i = 0;

	while (args[i] != NULL)
		free(args[i++]);
	free(args);
}

/**
 * exit_st - Exits shell
 * @exit_stat: Exit status code
 * @args: Arguments
 * @flname: File name
 * @pcount: Process count
 */
void exit_st(int exit_stat, char **args, char *flname, int pcount)
{
	if (exit_stat >= 0)
	{
		free_args(args);
		exit(exit_stat);
	}
	else
		printf("%s: %d: %s: Illegal number: %s\n",
					flname, pcount, args[0], args[1]);
	free_args(args);
}
