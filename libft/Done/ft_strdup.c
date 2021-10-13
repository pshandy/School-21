size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*result;

	size = strlen(s) + 1;
	result = malloc(size);
	if (result == 0)
		return(0);
	return((char*) memcpy (result, s, size));
}
