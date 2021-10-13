/*
 * int ft_isacii(int c)
 *
 * Checks whether c is a 7-bit unsigned char value
 * that fits into the ASCII character set.
 *
 * Return: 0 or 1.
 */

#include "libft.h"

int	ft_isacii(int c)
{
	return (c >= 0 && c <= 127);
}
