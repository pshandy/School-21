/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 09:53:20 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/27 10:03:59 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*copy(char *dest, char *src)
{
	char	*dest_copy;
	int		i;

	dest_copy = dest;
	while (*dest)
	{
		dest++;
	}
	i = 0;
	while (*src)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	return (dest_copy);
}

int	getlen(char **strs, int size)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	return (size);
}

int	getseplen(char *sep)
{
	int	length;

	length = 0;
	while (sep[length])
	{
		length++;
	}
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		len;
	char	*out;
	int		sep_length;

	if (size == 0)
	{
		out = malloc(sizeof(char));
		*out = 0;
		return (out);
	}
	sep_length = getseplen(sep);
	len = getlen(strs, size);
	len = len + 1 + sep_length * (size - 1);
	out = malloc(sizeof(char) * len);
	i = 0;
	while (i < size)
	{
		out = copy (out, strs[i]);
		if (i != size - 1)
			out = copy (out, sep);
		i++;
	}
	return (out);
}
