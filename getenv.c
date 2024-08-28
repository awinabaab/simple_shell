#include "main.h"

/**
 * _getenv - Gets the value of an environment variable
 *
 * @name: Environment variable name
 *
 * Return: The environment variable string given
 */

char *_getenv(const char *name)
{
	char *value, *env, *token;
	int i = 0;

	while (environ[i] != NULL)
	{
		env = _strdup(environ[i]);
		if (env == NULL)
			return (NULL);

		token = strtok(env, "=");
		if (token && _strcmp(token, name) == 0)
		{
			value = _strdup(strtok(NULL, "="));
			free(env);
			return (value);
		}
		free(env);
		i++;
	}
	return (NULL);
}
