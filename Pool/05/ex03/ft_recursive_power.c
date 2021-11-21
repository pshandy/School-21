/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:44:16 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/24 16:45:05 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 1)
	{
		if (power < 0)
			return (0);
		return (1);
	}
	else
		return (nb * ft_recursive_power(nb, power - 1));
}
