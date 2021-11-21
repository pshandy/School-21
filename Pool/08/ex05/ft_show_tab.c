/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:32:26 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/28 12:33:29 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
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

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		ft_putnbr(par->size);
		ft_putchar('\n');
		ft_putstr(par->str);
		ft_putchar('\n');
		ft_putstr(par->copy);
		ft_putchar('\n');
		par++;
	}
}
