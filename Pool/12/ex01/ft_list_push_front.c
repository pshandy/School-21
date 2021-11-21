/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:18:22 by pshandy           #+#    #+#             */
/*   Updated: 2021/09/02 15:18:42 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*temp;

	if (*begin_list)
	{
		temp = ft_create_elem(data);
		temp->next = *begin_list;
		*begin_list = temp;
	}
	else
	{
		*begin_list = ft_create_elem(data);
	}
}
