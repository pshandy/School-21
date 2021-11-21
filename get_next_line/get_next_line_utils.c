/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:26:24 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/26 12:26:26 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	const char	*end;

	end = str;
	while (*end != '\0')
		end++;
	return (end - str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	if (src == NULL && dest == NULL)
		return (NULL);
	s = (const char *)src;
	d = (char *)dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*result;

	size = ft_strlen(s) + 1;
	result = malloc(size);
	if (result == 0)
		return (0);
	return ((char *)ft_memcpy(result, s, size));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*strc;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	strc = str;
	while (*s1 != '\0')
		*str++ = *s1++;
	while (*s2 != '\0')
		*str++ = *s2++;
	*str = '\0';
	return (strc);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
		*ptr++ = c;
	return (s);
}
