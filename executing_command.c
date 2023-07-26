#include "our_shell.h"


/**
 * cmd_exiter - handles exit commands
 * @cmvd: command tokens
 * @str: input from std
 *
 */
void cmd_exiter(char **cmvd, char *str)
{
free(str);
buff_free(cmvd);
exit(0);
}

#include "our_shell.h"

/**
 * execute - executes  command
 * @cp: the command path
 * @cmd:  array of command argument
 *
 */
void execute(char *cp, char **cmd)
{
pid_t _pid;
int token;
char **env = environ;

_pid = fork();
if (_pid < 0)
{
perror(cp);
}
if (_pid == 0)
{
execve(cp, cmd, env);
perror(cp);
free(cp);
buff_free(cmd);
exit(98);
}
else
wait(&token);
}

#include "our_shell.h"
/**
 * check - checks whether it is built-in function
 * @cmvd: user token inputs
 * @token: getline function
 * Return: 1 on success, 0 on failure
 */
int check(char **cmvd, char *token)
{
if (built_handler(cmvd, token))
return (1);
else if (**cmvd == '/')
{
execute(cmvd[0], cmvd);
return (1);
}
return (0);
}

#include "our_shell.h"

/**
 * path_adder - adds path to command
 * @path: path of the command
 * @cmvd: user-entered command
 * Return: buffer.
 */
char *path_adder(char *path, char *cmvd)
{
char *buffer;
size_t a = 0, b = 0;

if (cmvd == 0)
cmvd = "";

if (path == 0)
path = "";

buffer = malloc(sizeof(char) * (strlen(path) + strlen(cmvd) + 2));
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
while (cmvd[b])
{
buffer[a + b] = cmvd[b];
b++;
}
buffer[a + b] = '\0';
return (buffer);
}
