/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 08:47:08 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/25 08:47:10 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	nb_copy;
	int	div;
	int	result;

	nb_copy = nb;
	div = 1;
	result = 0;
	while (nb > 0)
	{
		nb = nb - div;
		div = div + 2;
		if (nb >= 0)
			result += 1;
	}
	if (result * result == nb_copy)
		return (result);
	return (0);
}
