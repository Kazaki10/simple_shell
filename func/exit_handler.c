#include "our_shell.h"

/**
 * handle_exit - Exit the shell
 * @args: An array of command arguments
 */

void handle_exit(char **args)
{
	int exit_code = 0;

	if (args[1] != NULL)
	{
		exit_code = atoi(args[1]);
	}

	should_exit = 1; /*Set the flag to exit the shell*/
	exit(exit_code);
}
