/*
 * void	*ft_memcpy(void *dest, const void *src, size_t n)
 *
 * Copies n bytes from memory area src to
 * memory area dest. The memory areas must not overlap.
 *
 * Return: pointer to dest.
 */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = (const char *)src;
	d = (char *)dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}
