#include "main.h"

	/**
	* _getenv - Gets the value of an environment variable
	*
	* @name: Environment variable name
	*
	* return: The environment variable string given
	*/char *_getenv(const char *name)
{
	char *value, *env, *token;
	int i = 0;

	while (environ[i] != NULL)
	{
		env = strdup(environ[i]);
		if (env == NULL)
			return (NULL);

		token = strtok(env, "=");
		if (token && strcmp(token, name) == 0)
		{
			value = strdup(strtok(NULL, "="));
			free(env);
			return (value);
		}
		free(env);
		i++;
	}
	return (NULL);
}
