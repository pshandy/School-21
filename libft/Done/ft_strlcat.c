#include "libft.h"

static

size_t ft_strlcat (char *dst, const char *src, size_t size)
{
	char	*d;
	const schar	*s;
	size_t	len;
	size_t	diff;

	d = dst;
	s = src;
	len = size;
	while(*d != '\0' && len != 0)
	{
		len--;
		d++;
	}
	len = d - dst;
	diff = size - len;
	if (diff == 0)
		return(len + ft_strlen(s));
	while (*s != '\0') {
		if (diff != 1) {
			*d++ = *s;
			diff--;
		}
		s++;
	}
	*d = '\0';
	return(len + (s - src));
}
