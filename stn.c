#include "our_shell.h"

/**
 * print_promp - prints the prompt symbol ($)
 * If the shell is in interactive mode
 *	prints the prompt symbol to the standard error file descriptor
 */
void print_promp(void)
{
if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
tool.acti = 1;
if (tool.acti)
write(STDERR_FILENO, "$emyy ", 2);
}

#include "our_shell.h"

/**
* _putchar - writes the character
* @a: The character to print
*
* Return: On success 1.
* On error, -1 is returned and errno set appropriately
*/
int _putchar(char a)
{
return (write(1, &a, 1));
}

/**
* string_printer - prints a string
* @a: string
*
* Return: number of characters
*/
int string_printer(char *a)
{
int i = 0;

while (a[i] != '\0')
{
_putchar(a[i]);
i++;
}

return (i);
}

#include "our_shell.h"

/**
* env_printer - prints the environment string
*
* Return: 0
*/
void env_printer(void)
{
int g = 0;
char **ern = environ;

while (ern[g])
{
write(STDOUT_FILENO, (const void *)ern[g], strlen(ern[g]));
write(STDOUT_FILENO, "\n", 1);
g++;
}
}
