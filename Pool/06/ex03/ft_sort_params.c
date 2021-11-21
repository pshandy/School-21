/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:32:05 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/25 17:04:01 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_print(char *arr[], int len)
{
	int	i;

	arr++;
	i = 1;
	while (i < len)
	{
		while (**arr)
		{
			ft_putchar(**arr);
			*arr = *arr + 1;
		}
		ft_putchar('\n');
		arr++;
		i++;
	}
}

int	main(int len, char *argv[])
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < len - 1)
	{
		j = 1;
		while (j < len - i - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				temp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	ft_print(argv, len);
}
