char *ft_strchr(const char *str, int c);

char *ft_strrchr(const char *str, int c)
{
	char *saved;
	char *p;

    if (c == '\0')
      return ft_strchr (str, '\0');

    saved = 0;
    while ((p = ft_strchr (str, c)) != 0)
	{
		saved = p;
		str = p + 1;
    }
    return (char *) saved;
}
