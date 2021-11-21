/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:24:04 by pshandy           #+#    #+#             */
/*   Updated: 2021/09/02 15:24:17 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*temp;

	if (*begin_list)
	{
		temp = *begin_list;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = ft_create_elem(data);
	}
	else
	{
		*begin_list = ft_create_elem(data);
	}
}
