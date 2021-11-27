#include "libftprintf.h"

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_putchar(char c, int idx)
{
	(void)idx;
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

int	ft_atoi(const char *nptr)
{
	char	sign;
	int		result;

	while (ft_isspace(*nptr))
		nptr++;
	sign = '+';
	if (*nptr == '-')
	{
		sign = '-';
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	result = 0;
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	if (sign == '-')
		return (-result);
	return (result);
}
