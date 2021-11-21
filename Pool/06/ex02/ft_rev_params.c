/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:45:43 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/25 11:45:45 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	while (*argv)
	{
		argv++;
	}
	argv--;
	i = argc;
	while (i > 1)
	{
		while (**argv)
		{
			ft_putchar(**argv);
			*argv = *argv + 1;
		}
		ft_putchar('\n');
		i--;
		argv--;
	}
}
