/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 09:28:09 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/27 09:37:17 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*arr;
	unsigned int	len;
	int				i;
	unsigned int	j;

	len = max - min;
	if (min >= max)
		return (NULL);
	arr = malloc(sizeof(int) * len);
	i = min;
	j = 0;
	while (i < max)
	{
		arr[j] = i;
		i++;
		j++;
	}
	return (arr);
}
