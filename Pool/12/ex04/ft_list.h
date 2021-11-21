/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:23:52 by pshandy           #+#    #+#             */
/*   Updated: 2021/09/02 15:23:53 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_list	t_list;

struct	s_list
{
	void	*data;
	t_list	*next;
};

t_list	*ft_create_elem(void *data);

#endif
