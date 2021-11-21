/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 09:38:05 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/22 13:39:36 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *dest)
{
	int	length;

	length = 0;
	while (*dest++)
		length++;
	return (length);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	ft_strcpy(dest + ft_strlen(dest), src);
	return (dest);
}
