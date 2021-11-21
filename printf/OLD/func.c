#include "func.h"
#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

void		convert(int n, char *base)
{
	int	len;

	len = ft_strlen(base);
	if (n > len)
	{
		convert(n / len, base);
		convert(n % len, base);
	}
	else
		ft_putchar(base[n]);
}
