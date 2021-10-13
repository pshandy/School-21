/*
 * void *ft_calloc(size_t nmemb, size_t size)
 *
 * The ft_calloc() function shall allocate unused space for an array of
 * nmemb elements each of whose size in bytes is size.
 * The space shall be initialized to all bits 0.
 *
 * Return: a pointer to the allocated space.
 */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (p == 0)
		return (0);
	ft_memset(p, 0, nele * size);
	return (p);
}
