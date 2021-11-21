/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:16:02 by pshandy           #+#    #+#             */
/*   Updated: 2021/09/01 13:16:04 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*out;

	out = malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		out[i] = f(tab[i]);
		i++;
	}
	return (out);
}
