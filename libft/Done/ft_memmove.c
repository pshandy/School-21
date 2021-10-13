/*
 * void	*ft_memmove(void *dest, const void *src, size_t n)
 *
 * Copies n bytes from memory area src to memory area dest.
 * The memory areas may overlap.
 *
 * Return: pointer to dest.
 */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	if (dest < src)
		return (ft_memcpy(dest, src, n));
	else
	{
		s = (const char *)src + (n - 1);
		d = (char *)dest + (n - 1);
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}
