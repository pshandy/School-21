void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = (const char *)src;
	d = (char *)dest;
	while(n--)
	 	*d++ = *s++;
	return(dest);
}
