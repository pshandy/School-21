/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:28:34 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/25 14:28:36 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	base;

	base = nb;
	if (power < 0 && nb == 1)
		return (1);
	if (power < 0 && nb == -1)
		return (-1);
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (power > 1)
	{
		nb = nb * base;
		power--;
	}
	return (nb);
}
