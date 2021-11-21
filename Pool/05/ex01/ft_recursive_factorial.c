/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:42:08 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/24 16:42:45 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb <= 1)
	{
		if (nb < 0)
			return (0);
		return (1);
	}
	else
		return (nb * ft_recursive_factorial(nb - 1));
}
