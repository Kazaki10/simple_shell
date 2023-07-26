#include "our_shell.h"

/**
 * is_builtin_cmvd - Checks if a command is a built-in command
 * @command: The command to check
 * Return: 1 if the command is a built-in command, 0 otherwise
 */

int is_builtin_cmvd(const char *command)
{
	return (strcmp(command, "exit") == 0 || strcmp(command, "cd") == 0);
}
