/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 08:37:59 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/31 08:39:37 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

void	print_input(void)
{
	char	buffer;

	while (read(0, &buffer, 1))
		   write(1, &buffer, 1);
	return ;
}

void	print_file(char **argv)
{
	int		fd;
	int		i;
	char	buffer;

	i = 1;
	while (argv[i])
	{
		fd = open(argv[i], O_RDONLY);
		if (fd > -1)
		{
			while (read(fd, &buffer, 1))
				write(1, &buffer, 1);
		}
		else
		{
			ft_putstr("ft_cat: ");
			ft_putstr(argv[i]);
			ft_putstr(": No such file or directory\n");
		}
		i++;
	}
	close(fd);
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 1 || argv[1][0] == '-')
		print_input();
	else
		print_file(argv);
}
