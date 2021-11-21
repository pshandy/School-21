/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:25:51 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/24 10:57:39 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	get_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	check(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (base[i] < 33 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = get_len(base);
	if (nbr < 0 && check(base))
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr <= -base_len && check(base))
	{
		ft_putnbr_base(-(nbr / base_len), base);
		ft_putnbr_base(-(nbr % base_len), base);
	}
	else if (nbr >= base_len && check(base))
	{
		ft_putnbr_base(nbr / base_len, base);
		ft_putnbr_base(nbr % base_len, base);
	}
	else if (check(base))
	{
		if (nbr < 0)
			nbr = -nbr;
		write(1, &base[nbr], 1);
	}
}
