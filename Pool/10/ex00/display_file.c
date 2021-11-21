/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 08:32:46 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/31 08:35:21 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *c, int len)
{
	write(1, c, len);
}

int	display(char *filename)
{
	int		fd;
	char	buffer;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (-1);
	}
	while (read(fd, &buffer, 1))
		write(1, &buffer, 1);
	close (fd);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr("File name missing.\n", 19);
	}
	else if (argc > 2)
	{
		ft_putstr("Too many arguments.\n", 20);
	}
	else if (display(argv[1]) == -1)
	{
		ft_putstr("Cannot read file.\n", 18);
		return (-1);
	}
	return (0);
}
