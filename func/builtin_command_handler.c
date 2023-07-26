#include "our_shell.h"

/**
 * handle_builtin_cmvd - Handle  built-in commands
 * @command: built-in commands to handle
 * @argv: program name and their arguments
 */

void handle_builtin_cmvd(const char *command, char **argv)
{
	if (strcmp(command, "exit") == 0)
	{
	should_exit = 1
	}
	else if (strcmp(command, "cd") == 0)
	{
	handle_cd(argv);
	}
}
