int		ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
/*
* function copies up to Fa size - 1 characters from the NUL-terminated
* string Fa src to Fa dst , NUL-terminating the result.
*/

size_t	ft_strlcpy (char *dst, const char *src, size_t size)
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
	return(len);
}
