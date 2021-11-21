/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:14:51 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/31 11:14:53 by pshandy          ###   ########.fr       */
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

void	print_header(char *str, int pos, int argc)
{
	ft_putstr("==> ");
	ft_putstr(str);
	ft_putstr(" <==");
	if (pos + 1 != argc || str[1])
		ft_putstr("\n");
}

void	print_no_file(char *str)
{
	ft_putstr("ft_tail: ");
	ft_putstr(str);
	ft_putstr(": No such file or directory\n");
}

int	ft_atoi(char *str)
{
	int	num;

	num = 0;
	while (*str)
	{
		num = num * 10;
		num = num + (*str - '0');
		str++;
	}
	return (num);
}
