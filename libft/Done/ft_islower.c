/*
 * int ft_islower(int c)
 *
 * Checks for a lower-case character.
 * 
 * Return: 0 or 1.
 */

#include "libft.h"

int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
