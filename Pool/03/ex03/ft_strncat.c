/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 09:43:46 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/22 13:34:07 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *dest)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strncpy(char *dest, char *src, int nb)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < nb)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	ft_strncpy(dest + ft_strlen(dest), src, nb);
	return (dest);
}
