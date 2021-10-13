char *ft_strchr(const char *str, int c)
{
	char *str_copy;

	str_copy = (char *)str;
	while(1)
	{
		if (*str_copy == c)
			return((char *)str_copy);
		if (*str_copy == '\0')
			return(0);
		str_copy++;
	}
}
