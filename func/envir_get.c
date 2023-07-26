#include "our_shell.h"

/**
 * env_get - Get the value of an environment
 * @token: name of environment variable to retrieve
 *
 * Return: The value of the environment variable if found,else NULL
 */

char *env_get(const char *token)
{
	size_t token_length = strlen(token);
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(token, *env, token_length) == 0 && (*env)[token_length] == '=')
	{
		return (&(*env)[token_length + 1]);
	}
	}

	return (NULL);
}
