/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 09:51:17 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/31 09:57:37 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	print_no_file(char *str);
void	print_header(char *str, int pos, int argc);

int	illegal_offset_check(char **argv, int i, int start_pos)
{
	while (argv[start_pos][i])
	{
		if (!(argv[start_pos][i] >= '0' && argv[start_pos][i] <= '9'))
		{
			ft_putstr("ft_tail: illegal offset -- ");
			if (start_pos == 1)
				ft_putstr(&argv[start_pos][2]);
			else
				ft_putstr(&argv[start_pos][0]);
			ft_putstr("\n");
			return (1);
		}
		i++;
	}
	return (0);
}

void	print(int argc, char **argv, int s, char *offset)
{
	char	buffer;
	int		fd;
	int		k;

	k = s + 1;
	while (argv[k])
	{
		fd = open(argv[k], O_RDONLY);
		if (fd > -1)
		{
			if (argc > 4 || (argc > 3 && s == 1))
				print_header(argv[k], k, argc);
			lseek(fd, -ft_atoi(offset), 2);
			while (read(fd, &buffer, 1))
				write(1, &buffer, 1);
			if (k + 1 != argc)
				ft_putstr("\n");
		}
		else
			print_no_file(argv[k]);
		k++;
	}
}

int	body(int argc, char **argv)
{
	int		i;
	int		start_pos;
	char	*offset;

	if (argv[1][2])
	{
		i = 2;
		start_pos = 1;
	}
	else
	{
		i = 0;
		start_pos = 2;
	}
	if (illegal_offset_check(argv, i, start_pos))
		return (1);
	if (start_pos == 1)
		offset = &argv[start_pos][2];
	else
		offset = &argv[start_pos][0];
	print(argc, argv, start_pos, offset);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && !argv[1][2])
	{
		ft_putstr("ft_tail: option requires an argument -- c\n");
		return (1);
	}
	if (body(argc, argv))
	{
		return (1);
	}
	return (0);
}
