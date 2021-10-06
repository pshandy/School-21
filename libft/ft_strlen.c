int ft_strlen(const char *str)
{
	const char *end;

	end = str;
	while(*end)
		end++;
	return(end - str);
}
