void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;

	src = (const unsigned char *)s;
	while(n--)
	{
		if (*src == c)
			return((void *)src);
		src++;
	}
	return(0);
}
