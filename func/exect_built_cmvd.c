#include "our_shell.h"

/**
 * execute_builtin_cmvd - Executes a built-in command
 * @args: An array of command arguments
 */


void execute_builtin_cmvd(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		handle_exit(args);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		handle_cd(args);
	}
}
