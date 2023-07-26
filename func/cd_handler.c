#include "our_shell.h"

/**
 * handle_cd - Change directory
 * @args: An array of command arguments
 */

void handle_cd(char **args)
{
	char *dir, *error_msg;
	int result;

	if (args[1] != NULL && strcmp(args[1], "-") == 0)
	{
		dir = _getenv("OLDPWD");
		error_msg = "cd: previous directory not set\n";
	}
	else if (args[1] != NULL)
	{
		dir = args[1];
	}
	else
	{
		dir = _getenv("HOME");
		error_msg = "cd: home directory not set\n";
	}

	if (dir == NULL)
	{
		my_putstring(error_msg);
		return;
	}

	result = chdir(dir);
	if (result != 0)
	{
		perror("cd");
	}

}
