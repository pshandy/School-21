void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	if (dest < src)
		return(ft_memcpy(dest, src, n));
	else
	{
		s = (const char *)src + (n - 1);
		d = (char *)dest + (n - 1);
		while(n--)
			*d-- = *s--;
	}
	return(dest);
}
