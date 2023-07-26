#include "my_shell.h"

/**
 * my_strchr - locates a character in a string
 * @s : string
 * @c : Character to locate
 * Return: pointer to c or NULL is not found
 */

char *my_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
	if (*s == c)
		return ((char *) s);
	s++;
	}

	if (c == '\0')
	{
	return ((char *) s);
	}
	return (NULL);
}
