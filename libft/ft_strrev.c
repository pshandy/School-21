int ft_strlen(const char *str);

char *ft_strrev(char *str)
{
	int		len;
	int		i;
	char	temp;

	if (!str || !*str)
		return str;

	len = ft_strlen(str);

	i = 0;
	while(i < len / 2)
	{
		temp = str[len - 1 - i];
		str[len - 1 - i] = str[i];
		str[i] = temp;
		i++;
	}

	return str;
}
