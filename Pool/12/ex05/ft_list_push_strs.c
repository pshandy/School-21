/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:26:32 by pshandy           #+#    #+#             */
/*   Updated: 2021/09/02 15:26:48 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*elem;
	t_list	*elem2;

	if (size <= 0)
		return (0);
	elem = ft_create_elem(strs[0]);
	i = 1;
	while (i < size)
	{
		elem2 = ft_create_elem(strs[i]);
		elem2->next = elem;
		elem = elem2;
		i++;
	}
	return (elem);
}
