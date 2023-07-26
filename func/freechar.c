#include "our_shell.h"

/**
* freechar - Frees memory allocated for a char ** array.
* @arr: The char ** array to be freed.
* Return: None.
*/

void freechar(char **arr)
{
int i = 0;

if (arr == NULL)
return;
while (arr[i])
{
free(arr[i]);
i++;
}
if (arr[i] == NULL)
free(arr[i]);
free(arr);
}
