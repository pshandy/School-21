void	*ft_memset(void *s, int c, size_t n)

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *p;
	p = malloc(nmemb * size);
	if (p == 0)
		return 0;
	ft_memset(p, 0, nele * size);
	return p;
}
