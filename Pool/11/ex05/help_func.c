/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:23:17 by pshandy           #+#    #+#             */
/*   Updated: 2021/09/01 14:32:09 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
	}
	if (nb <= -10)
	{
		ft_putnbr(-(nb / 10));
		ft_putnbr(-(nb % 10));
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		if (nb < 0)
			nb = -nb;
		ft_putchar('0' + nb);
	}
}

int	get_result(char *str, int j)
{
	int	result;
	int	i;

	i = j;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + (str[i] - '0');
		i++;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i])
	{
		if (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))
			return (0);
		if (str[i] == '-')
			sign = sign * (-1);
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = get_result(str, i);
			break ;
		}
		i++;
	}
	return (result * sign);
}
