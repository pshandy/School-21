/*
 * int ft_isalpha(int c)
 *
 * Checks for an alphabetic character
 * 
 * Return: 0 or 1.
 */

#include "libft.h"

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
