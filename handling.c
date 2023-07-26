#include "our_shell.h"

/**
 * built_handler - handles execution of built-in functions
 * @cmvd: cmd token
 * @string: input read from std
 * Return: 0 sucess.
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
 * sig_handler - handles the signal
 * @s: signal number
 */

void sig_handler(int s)
{
(void)s;
write(STDERR_FILENO, "\n", 1);
write(STDERR_FILENO, "$ ", 2);
}
#include "our_shell.h"

/**
 * path_finder - finds the PATH variable
 * Return: NULL
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
