#include "our_shell.h"

/**
 * built_handler - handles the execution of pre-built functions
 * @cmvd: tokenized commands
 * @string: input read from stdin
 *
 * This function compares the first command token with the built-in functions.
 * If a match is found, it calls the corresponding built in handler function.
 *
 * Return: 1 if executed, 0 if not
 */
int built_handler(char **cmvd, char *string)
{
struct builtin builtin = {"env", "exit"};

if (strcmp(*cmvd, builtin.env) == 0)
{
env_printer();
return (1);
}
else if (strcmp(*cmvd, builtin.exit) == 0)
{
cmd_exiter(cmvd, string);
return (1);
}
return (0);
}

#include "our_shell.h"

/**
 * buff_free - frees buffers
 * @buffer: buffer to be freed
 *
 * This function frees the memory allocated for the buffer.
 */
void buff_free(char **buffer)
{
int i = 0;

if (!buffer || buffer == NULL)
return;
while (buffer[i])
{
free(buffer[i]);
i++;
}
free(buffer);
}

#include "our_shell.h"

/**
 * sig_handler - handles the signal and keeps track of the active mode
 * @s: the signal number
 *
 * This function is the signal handler for a specific signal.
 * It writes a newline character and "$ "
 *	to the standard error file descriptor.
 */

void sig_handler(int s)
{
(void)s;
write(STDERR_FILENO, "\n", 1);
write(STDERR_FILENO, "$ ", 2);
}
#include "our_shell.h"

/**
 * path_finder - finds the PATH variable from the global environment
 *
 * This function searches for the PATH variable in the global environment.
 * If found, it returns the value of the PATH variable.
 * If not found
 * Return: NULL.
 */
char *path_finder(void)
{
int p;
char **ern = environ, *path = NULL;

while (*ern)
{
if (strncmp(*ern, "PATH=", 5) == 0)
{
path = *ern;
while (*path && p < 5)
{
path++;
p++;
}
return (path);
}
ern++;
}
return (NULL);
}
