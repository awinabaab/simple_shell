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
	struct stat st;
	int status;

	if (args == NULL)
		return (2);
	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		exit(0);
	}
	else if (stat(args[0], &st) == -1)
	{
		printf("%s: %d: %s: not found\n", flname, pcount, args[0]);
		return (2);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (2);
	} else if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
			exit(2);
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			return (2);
		}
	}
	return (0);
}
