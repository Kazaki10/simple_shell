#include "our_shell.h"

/**
 * path_tester - checks whether the path is valid
 * @path: tokenized path
 * @command: user entered command
 * Return: path appended with command on success
*/
char *path_tester(char **path, char *command)
{
int z = 0;
char *output;

while (path[z])
{
output = path_adder(path[z], command);
if (access(output, F_OK | X_OK) == 0)
return (output);
free(output);
z++;
}
return (NULL);
}

/**
 * tkn_iz - creates tokens from the given input string
 * @str: input string to be tokenized
 *
 * Return: array of strings
*/
char **tkn_iz(char *str)
{
char *buffer = NULL, *bvp = NULL, *item = NULL, *mem = " :\t\r\n";
char **cmvvd = NULL;
int sizetkn = 1;
size_t indice = 0, flag = 0;

buffer = strdup(str);
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
cmvvd = malloc(sizeof(char *) * (sizetkn + 1));
item = strtok(buffer, mem);
while (item)
{
cmvvd[indice] = strdup(item);
if (cmvvd[indice] == NULL)
{
free(cmvvd);
return (NULL);
}
item = strtok(NULL, mem);
indice++;
}
cmvvd[indice] = '\0';
free(buffer);
return (cmvvd);
}
