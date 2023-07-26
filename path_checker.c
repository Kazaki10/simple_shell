#include "our_shell.h"

/**
 * path_checker - checks if the path is valid or not.
 * @path: path tokened.
 * @cmd: Users command input.
 * Return: path conjoin with command on success
*/
char *path_checker(char **path, char *cmd)
{
int x = 0;
char *output;

while (path[x])
{
output = path_adder(path[x], cmd);
if (access(output, F_OK | X_OK) == 0)
return (output);
free(output);
x++;
}
return (NULL);
}

/**
 * tok_ner - creates tokens from given input
 * @st: input string to transform into token
 *
 * Return: array of strings
*/
char **tok_ner(char *st)
{
char *buffer = NULL, *bvp = NULL, *item = NULL, *mem = " :\t\r\n";
char **cmvd = NULL;
int sizetkn = 1;
size_t indice = 0, flag = 0;

buffer = strdup(st);
if (!buffer)
return (NULL);
bvp = buffer;

while (*bvp)
{
if (strchr(mem, *bvp) != NULL && flag == 0)
{
sizetkn++;
flag = 1;
}
else if (strchr(mem, *bvp) == NULL && flag == 1)
flag = 0;
bvp++;
}
cmvd = malloc(sizeof(char *) * (sizetkn + 1));
item = strtok(buffer, mem);
while (item)
{
cmvd[indice] = strdup(item);
if (cmvd[indice] == NULL)
{
free(cmvd);
return (NULL);
}
item = strtok(NULL, mem);
indice++;
}
cmvd[indice] = '\0';
free(buffer);
return (cmvd);
}
