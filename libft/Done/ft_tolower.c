/*
 * int ft_tolower(int c)
 *
 * Returns the lowercase letter corresponding to the argument passed;
 * otherwise, returns the argument unchanged.
 */

#include "libft.h"

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	return (c);
}
