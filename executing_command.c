#include "our_shell.h"


/**
 * exiting_cmd - Handle the exit mechanism
 * @tcmd: The token command
 * @stn: Input that  read from stdin
 *  function that frees the allocated memory and exit program.
 */
void exiting_cmd(char **tcmd, char *stn)
{
free(stn);
buff_free(tcmd);
exit(0);
}

#include "our_shell.h"

/**
 * cmd_execute - executes a command
 * @pcm: cmd pathway
 * @vra: array of command arguments
 * waits for the child process to finish before the return.
 */
void cmd_execute(char *pcm, char **vra)
{
pid_t _pid;
int tokens;
char **env = environ;

_pid = fork();
if (_pid < 0)
{
perror(pcm);
}
if (_pid == 0)
{
execve(pcm, vra, env);
perror(pcm);
free(pcm);
buff_free(vra);
exit(98);
}
else
wait(&tokens);
}

#include "our_shell.h"
/**
 * checker - a checker that checks if its a built-in function.
 * @uti: user token inputs.
 * @tokens: getline function
 *
 * Return: 1 on success, and 0 on fail.
 */
int checker(char **uti, char *tokens)
{
if (built_handler(uti, tokens))
return (1);
else if (**uti == '/')
{
execute(uti[0], uti);
return (1);
}
return (0);
}

#include "our_shell.h"

/**
 * path_adding - adds a  path to commands
 * @path: path of given command
 * @uti: user-entered command
 *
 * Return: buffer containing the  path and command
 * OR NULL if memory allocation fails
 */
char *path_adding(char *path, char *uti)
{
char *buffer;
size_t a = 0, b = 0;

if (uti == 0)
uti = "";

if (path == 0)
path = "";

buffer = malloc(sizeof(char) * (strlen(path) + strlen(uti) + 2));
if (!buffer)
return (NULL);

while (path[a])
{
buffer[a] = path[a];
a++;
}

if (path[a - 1] != '/')
{
buffer[a] = '/';
a++;
}
while (uti[b])
{
buffer[a + b] = uti[b];
b++;
}
buffer[a + b] = '\0';
return (buffer);
}
