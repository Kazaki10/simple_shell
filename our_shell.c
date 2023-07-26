#include "our_shell.h"
/**
 * main - The Entry Point.
 * @ac: The argument count.
 * @av: The argument vector.
 * @env:The environment vector.
 *
 * Return: 0.
 */

int main(int ac, char **av, char *env[])
{
char *line = NULL, *pathcommand = NULL, *path = NULL;
size_t bufsize = 0;
ssize_t linesize = 0;
char **command = NULL, **paths = NULL;
(void)env, (void)v;
if (ac < 1)
return (-1);
signal(SIGINT, sig_handler);
while (1)
{
buff_free(command);
buff_free(paths);
free(pathcommand);
print_promp();
linesize = getline(&line, &bufsize, stdin);
if (linesize < 0)
break;
items.line_c++;
if (line[linesize - 1] == '\n')
line[linesize - 1] = '\0';
command = tkn_iz(line);
if (command == NULL || *command == NULL || **command == '\0')
continue;
if (check(command, line))
continue;
path = path_finder();
paths = tkn_iz(path);
pathcommand = path_tester(paths, command[0]);
if (!pathcommand)
perror(av[0]);
else
execute(pathcommand, command);
}
if (linesize < 0 && tool.acti)
write(STDERR_FILENO, "\n", 1);
free(line);
return (0);
}
