/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:20:19 by pshandy           #+#    #+#             */
/*   Updated: 2021/09/02 15:20:45 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*temp;

	temp = begin_list;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
