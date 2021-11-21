/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:43:55 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/25 11:44:18 by pshandy          ###   ########.fr       */
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

	i = 1;
	argv++;
	while (i < argc)
	{
		while (**argv)
		{
			ft_putchar(**argv);
			*argv = *argv + 1;
		}
		ft_putchar('\n');
		i++;
		argv++;
	}
}
