/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 09:39:35 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/27 09:43:19 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	i;
	int				*arr;
	unsigned int	len;

	len = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	arr = malloc (sizeof(int) * len);
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	*range = arr;
	return (i);
}
