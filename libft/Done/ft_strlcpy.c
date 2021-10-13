/*
* size_t ft_strlcpy (char *dst, const char *src, size_t size)
*
* Copies up to Fa size - 1 characters from the NUL-terminated
* string Fa src to Fa dst , NUL-terminating the result.
*
* Return: pointer to the destination string dest.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (len + 1 < size)
		ft_memcpy(dst, src, len + 1);
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (len);
}
