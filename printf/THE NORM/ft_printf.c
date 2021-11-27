/*
 * int		ft_printf(const char *spec, ...);
 *
 * %c print a single character.
 * %s print a string of characters.
 * %p The void * pointer argument is printed in hexadecimal.
 * %d print a decimal (base 10) number.
 * %i print an integer in base 10.
 * %u print an unsigned decimal (base 10) number.
 * %x print a number in hexadecimal (base 16), with lowercase.
 * %X print a number in hexadecimal (base 16), with uppercase.
 * %% print a percent sign.
 *
 * Additional flags: '-' '0' '.' '#' ' ' '+'
 */

#include "libftprintf.h"

int	print_char(t_props props, va_list vlist, const char *c, int index)
{
	int	l;

	l = 1;
	if (!(props.flags & FLAGS_LEFT))
		while (l++ < props.width)
			ft_putchar(' ', index++);
	ft_putchar(va_arg(vlist, int), index++);
	if (props.flags & FLAGS_LEFT)
		while (l++ < props.width)
			ft_putchar(' ', index++);
}

void	print_number()
{
	return ;
}

void	print_pointer()
{
	return ;
}

void	print_percent()
{
	return ;
}

void	print_string()
{
	return ;
}

int	check_char(char *c)
{
	if (*c == 'd' || *c == 'i' || *c == 'u' || *c == 'x' || *c == 'X')
		print_number();
	else if (*c == 'p')
		print_pointer();
	else if (*c == 'c')
		print_char(props, vlist, c++, index++);
	else if (*c == '%')
		print_percent();
	else if (*c == 's')
		print_string();
}

int	_ft_printf(const char *c, va_list vlist)
{
	int		index;
	t_props	props;

	index = 0;
	while (*c)
	{
		if (*c != '%')
		{
			ft_putchar(*c, index++);
			c++;
			continue ;
		}
		else
			c++;
		check_char(c);
	}
	return (index);
}

int	ft_printf(const char *spec, ...)
{
	int		ret;
	va_list	vlist;

	va_start(vlist, spec);
	ret = _ft_printf(spec, vlist);
	va_end(vlist);
	return (ret);
}
