#include "libftprintf.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_putchar(char c, int index)
{
	(void)index;
	write(1, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	const char	*end;

	end = str;
	while (*end != '\0')
		end++;
	return (end - str);
}
