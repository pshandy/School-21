/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:02:49 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/28 12:05:11 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>
# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define ODD_MSG "I have an odd number of arguments."
# define EVEN_MSG "I have an even number of arguments."
# define EVEN(x) x % 2 == 0
typedef int	t_bool;

#endif
