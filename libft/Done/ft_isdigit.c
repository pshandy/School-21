/*
 * int ft_isdigit(int c)
 *
 * Checks for a digit (0 through 9).
 *
 * Return: 0 or 1.
 */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
