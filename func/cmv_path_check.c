#include "our_shell.h"

/**
 * check_cmd_path - Check the command path
 * @cmvd: The command to check
 * @cmd_path: Buffer to store the command path
 * @path_var: The value of the PATH environment variable
 * Return: 1 if the command is found in the path, 0 otherwise
 */


int check_cmd_path(const char *cmvd, char *cmd_path, char *path_var)
{
	char *path_item;

	store_path_var(&path_var); /*Store the PATH variable*/
	/*Check if the command contains a '/'*/
	if (strchr(cmvd, '/') != NULL)
	{
	/*The command contains a '/', treat it as an absolute or relative path*/
	if (access(cmvd, X_OK) == 0)
	{
	strcpy(cmd_path, cmvd);
	return (1);
	}
	}
	else
	{
	/*The command does not contain a '/'*/
	/* search for it in the stored PATH variable*/
	path_item = strtok(path_var, ":");

	while (path_item != NULL)
		{
		strcpy(cmd_path, path_item);
		strcat(cmd_path, "/");
		strcat(cmd_path, cmvd);
		if (access(cmd_path, X_OK) == 0)
		{
		return (1);
		}
		path_item = strtok(NULL, ":");
		}
	}

	return (0);
}

/**
 * store_path_var - Store the value of the PATH variable
 * @path_var: Pointer to the variable to store the PATH value
 */
void store_path_var(char **path_var)
{
	char *path = _getenv("PATH");

	if (path != NULL)
	{
		*path_var = strdup(path);
	}

}
