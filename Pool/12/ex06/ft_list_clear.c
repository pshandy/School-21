/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:28:54 by pshandy           #+#    #+#             */
/*   Updated: 2021/09/02 15:29:05 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	if (begin_list && (begin_list)->next)
	{
		ft_list_clear((begin_list)->next, free_fct);
	}
	free(begin_list);
	begin_list = NULL;
}
