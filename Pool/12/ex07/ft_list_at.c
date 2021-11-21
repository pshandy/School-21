/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:33:43 by pshandy           #+#    #+#             */
/*   Updated: 2021/09/02 15:33:44 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list	*temp;
	int		i;

	temp = begin_list;
	i = 0;
	while (i < (int) nbr)
	{
		temp = temp->next;
		i++;
	}
	return (temp);
}
