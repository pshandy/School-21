/*
 * char *ft_strchr(const char *str, int c)
 *
 * Returns a pointer to the first occurrence
 * of the character c in the string str.
 *
 * Return: pointer to the matched character or NULL if the
 * character is not found.  The terminating null byte
 * is considered part of the string, so that if c is
 * specified as '\0', these functions return a
 * pointer to the terminator.
 */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*str_copy;

	str_copy = (char *)str;
	while (1)
	{
		if (*str_copy == c)
			return ((char *)str_copy);
		if (*str_copy == '\0')
			return (0);
		str_copy++;
	}
}
