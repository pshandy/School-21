/*
 * int ft_toupper(int c)
 *
 * Returns the uppercase letter corresponding to the argument passed;
 * otherwise, returns the argument unchanged.
 */

#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}
