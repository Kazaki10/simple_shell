#include "our_shell.h"

/**
 * my_strcpy - Entry point
 *
 * Description: Copies the string pointed to by src
 * @dest: Where to copy to
 * @src: String to be copied
 * Return: Pointer to dest
 */

char *my_strcpy(char *dest, const char *src)
{
	int i, len = 0;

	while (src[len] != '\0')
		len++;
	len++;

	for (i = 0; i < len; i++)
		dest[i] = src[i];

	return (dest);
}

/**
 * my_strcat - concatenates two strings,
 * @dest: destination.
 * @src: source.
 * Return: the pointer to dest.
 */
char *my_strcat(char *dest, const char *src)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (dest[len])
	{
		len++;
	}
		while (src[i])
		{
			dest[len + i] = src[i];
			i++;
		}
		dest[len + i] = '\0';

	return (dest);
}

/**
 * my_strcmp - compare 2 string
 * @s1:first string
 * @s2:second string
 * Return:result of the comparaison
 */

int	my_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * my_putstring - Outputs a string without a newline character
 * @str: The string to be outputted
 */
void my_putstring(char *str)
{
	int i;

	if (str == NULL)
		return;

	for (i = 0; str[i] != '\0'; ++i)
	{
		putchar(str[i]);
	}
}

/**
 * my_strlen - return the length of a string
 * @s: char to check
 * Return: length of the string
 */

int	my_strlen(char *s)
{
	char	*str;

	str = s;
	while (*str)
	{
		str++;
	}
	return (str - s);
}
