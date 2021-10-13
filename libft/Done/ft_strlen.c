int ft_strlen(const char *str)
{
	const char *end;

	end = str;
	while(*end != '\0')
		end++;
	return(end - str);
}
