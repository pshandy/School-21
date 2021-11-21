/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:43:53 by pshandy           #+#    #+#             */
/*   Updated: 2021/09/02 15:44:18 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *bl, void (*f)(void *), void *df, int (*c)())
{
	while (bl)
	{
		if ((*c)(bl->data, df) == 0)
			(*f)(bl->data);
		bl = bl->next;
	}
}
