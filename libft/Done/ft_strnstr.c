char	*ft_strnstr (const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return((char *)big);
	i = 0;
	while(big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			j = 1;
			while(little[j] != '\0' && big[i + j] == little[j] &&
						(i + j) < len)
					j++;
			if (little[j] == '\0')
				return((char *)&big[i]);
		}
		i++;
	}
	return(0);
}
