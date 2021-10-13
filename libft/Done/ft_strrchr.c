char *ft_strrchr(const char *str, int c)
{
	char *save;

	save = 0;
	while(1)
	{
		if (*str == c)
			save = (char *)str;
		if (*str == '\0')
			return(save);
		str++;
	}
}
