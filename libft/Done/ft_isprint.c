/*
 * int ft_isprint(int c)
 *
 * Checks for any printable character including space.
 * 
 * Return: 0 or 1.
 */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
