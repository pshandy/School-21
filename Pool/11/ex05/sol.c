/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:16:41 by pshandy           #+#    #+#             */
/*   Updated: 2021/09/01 14:42:51 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	plus(int a, int b);
void	minus(int a, int b);
void	division(int a, int b);
void	multiplication(int a, int b);
void	modulo(int a, int b);
int		ft_atoi(char *str);
void	ft_putchar(char c);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	operator_check(char **argv)
{
	char	**a;

	a = argv;
	a++;
	a++;
	if (ft_strlen(*a) != 1)
		return (1);
	if (**a != '+' && **a != '-' && **a != '/' && **a != '*' && **a != '%')
		return (1);
	return (0);
}

int	checks(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	if (operator_check(argv))
	{
		ft_putchar('0');
		ft_putchar('\n');
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		index;
	char	*s;
	void	((*p[5])(int x, int y));

	s = "+-*/%\0";
	p[0] = &plus;
	p[1] = &minus;
	p[2] = &multiplication;
	p[3] = &division;
	p[4] = &modulo;
	if (checks(argc, argv))
		return (1);
	index = 0;
	while (s[index])
	{
		if (argv[2][0] == s[index])
		{
			p[index](ft_atoi(argv[1]), ft_atoi(argv[3]));
			break ;
		}
		index++;
	}
}
