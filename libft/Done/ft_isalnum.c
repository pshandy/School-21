/*
 * int ft_isalnum(int c)
 *
 * Checks for an alphanumeric character.
 * 
 * Return: 0 or 1.
 */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
