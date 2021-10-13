/*
 * int ft_isupper(int c)
 *
 * Checks for a Upper-case character.
 * 
 * Return: 0 or 1.
 */

#include "libft.h"

int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
