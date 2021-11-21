/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:27:34 by pshandy           #+#    #+#             */
/*   Updated: 2021/09/01 14:27:35 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);

void	plus(int a, int b)
{
	ft_putnbr(a + b);
	ft_putchar('\n');
}

void	minus(int a, int b)
{
	ft_putnbr(a - b);
	ft_putchar('\n');
}

void	division(int a, int b)
{
	if (b == 0)
		ft_putstr("Stop : division by zero");
	else
		ft_putnbr(a / b);
	ft_putchar('\n');
}

void	multiplication(int a, int b)
{
	ft_putnbr(a * b);
	ft_putchar('\n');
}

void	modulo(int a, int b)
{
	if (b == 0)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(a % b);
	ft_putchar('\n');
}
