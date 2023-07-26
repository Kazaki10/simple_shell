#include "our_shell.h"
/**
 * our_getline -  Get input.
 * Return: input.
 */


char *our_getline(void)
{
	int tmp;
	char *lptr = NULL;
	size_t n = 0;

	tmp = getline(&lptr, &n, stdin);
	if (tmp == EOF)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		exit(0);
	}
	return (lptr);
}
