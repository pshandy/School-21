/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:56:46 by pshandy           #+#    #+#             */
/*   Updated: 2021/09/01 14:01:37 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
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

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int		length;
	char	*temp;
	int		i;
	int		j;

	length = get_len(tab);
	i = 0;
	while (i < length - 1)
	{
		j = 0;
		while (j < length - 1 - i)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
