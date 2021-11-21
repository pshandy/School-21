/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:15:10 by pshandy           #+#    #+#             */
/*   Updated: 2021/09/02 15:15:47 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp == NULL)
		return (NULL);
	tmp->data = data;
	tmp->next = NULL;
	return (tmp);
}
