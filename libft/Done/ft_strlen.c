/*
 * int ft_strlen(const char *str)
 *
 * Calculates the length of the string pointed
 * to by str, excluding the terminating null byte ('\0').
 *
 * Return: number of bytes in the string
 * pointed to by str.
 */

#include "libft.h"

int	ft_strlen(const char *str)
{
	const char	*end;

	end = str;
	while (*end != '\0')
		end++;
	return (end - str);
}
