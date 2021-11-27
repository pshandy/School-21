#include "libftprintf.h"
#include <stdio.h>

char	*get_flags(char *spec, t_props *props)
{
	props->flags = 0;
	while (*spec == '0' || *spec == '-' || *spec == '+' || *spec == ' '
		|| *spec == '#')
	{
		if (*spec == '0')
			props->flags |= FLAGS_ZEROPAD;
		else if (*spec == '-')
			props->flags |= FLAGS_LEFT;
		else if (*spec == '+')
			props->flags |= FLAGS_PLUS;
		else if (*spec == ' ')
			props->flags |= FLAGS_SPACE;
		else if (*spec == '#')
			props->flags |= FLAGS_HASH;
		spec++;
	}
	return (spec);
}

char	*get_width(char *spec, t_props *props)
{
	props->width = 0;
	if (ft_isdigit(*spec))
	{
		props->width = ft_atoi(spec);
		while (ft_isdigit(*spec))
			spec++;
	}
	return (spec);
}

char	*get_precision(char *spec, t_props *props)
{
	props->precision = 0;
	if (*spec == '.')
	{
		props->flags |= FLAGS_PRECISION;
		spec++;
		if (ft_isdigit(*spec))
			props->precision = ft_atoi(spec);
		while (ft_isdigit(*spec))
			spec++;
	}
	return (spec);
}

char	*handle_char(char *spec, t_props *props, int *idx, va_list *vlist)
{
	int	l;

	l = 1;
	if (!(props->flags & FLAGS_LEFT))
		while (l++ < props->width)
			ft_putchar(' ', (*idx)++);
	ft_putchar(va_arg(*vlist, int), (*idx)++);
	if (props->flags & FLAGS_LEFT)
		while (l++ < props->width)
			ft_putchar(' ', (*idx)++);
	return (++spec);
}

char	*handle_string(char *spec, t_props *props, int *idx, va_list *vlist)
{
	const char	*p;
	int			l;

	p = va_arg(*vlist, char *);
	l = ft_strlen(p);
	if (props->flags & FLAGS_PRECISION)
		if (l >= props->precision)
			l = props->precision;
	if (!(props->flags & FLAGS_LEFT))
		while (l++ < props->width)
			ft_putchar(' ', (*idx)++);
	while ((*p != 0) && (!(props->flags & FLAGS_PRECISION)
			|| props->precision--))
		ft_putchar(*(p++), (*idx)++);
	spec++;
	if (props->flags & FLAGS_LEFT)
		while (l++ < props->width)
			ft_putchar(' ', (*idx)++);
	return (spec);
}

char	*handle_percent(char *spec, int *idx)
{
	ft_putchar('%', (*idx)++);
	return (++spec);
}

char	*handle_pointer(char *spec, t_props *props, int *idx, va_list *vlist)
{
	int	value;

	value = (int) va_arg(*vlist, void *);
	props->width = sizeof(void *) * 2U;
	props->flags |= FLAGS_ZEROPAD | FLAGS_UPPERCASE;
	props->base = 16;
	*idx = ft_itoa(value, *props, value > 0, *idx);
	return (++spec);
}

void	handle_signed(t_props *props, int *idx, va_list *vlist)
{
	int	value;

	value = va_arg(*vlist, int);
	if (value > 0)
		*idx = ft_itoa(value, *props, value > 0, *idx);
	else
		*idx = ft_itoa(-value, *props, value > 0, *idx);
}

void	handle_unsigned(t_props *props, int *idx, va_list *vlist)
{
	unsigned int	value;

	value = va_arg(*vlist, unsigned int);
	*idx = ft_itoa(value, *props, value > 0, *idx);
}

char	*handle_number(char *spec, t_props *props, int *idx, va_list *vlist)
{
	if (*spec == 'x' || *spec == 'X')
		props->base = 16;
	else
	{
		props->base = 10;
		props->flags &= ~FLAGS_HASH;
	}
	if (*spec == 'X')
		props->flags |= FLAGS_UPPERCASE;
	if ((*spec != 'i') && (*spec != 'd'))
		props->flags &= ~(FLAGS_PLUS | FLAGS_SPACE);
	if (props->flags & FLAGS_PRECISION)
		props->flags &= ~FLAGS_ZEROPAD;
	if ((*spec == 'i') || (*spec == 'd'))
		handle_signed(props, idx, vlist);
	else
		handle_unsigned(props, idx, vlist);
	return (++spec);
}

char	*_ft_printf(char *spec, int *idx, va_list *vlist)
{
	t_props	props;

	spec = get_flags(spec, &props);
	spec = get_width(spec, &props);
	spec = get_precision(spec, &props);
	if (*spec == 'c')
		spec = handle_char(spec, &props, idx, vlist);
	else if (*spec == 's')
		spec = handle_string(spec, &props, idx, vlist);
	else if (*spec == '%')
		spec = handle_percent(spec, idx);
	else if (*spec == 'p')
		spec = handle_pointer(spec, &props, idx, vlist);
	else if (*spec == 'd' || *spec == 'i' || *spec == 'u'
		|| *spec == 'x' || *spec == 'X')
		spec = handle_number(spec, &props, idx, vlist);
	return (spec);
}

int	ft_printf(const char *spec, ...)
{
	int		idx;
	va_list	vlist;

	va_start(vlist, spec);
	idx = 0;
	while (*spec)
	{
		if (*spec != '%')
		{
			ft_putchar(*spec++, idx++);
			continue ;
		}
		else
			spec++;
		spec = _ft_printf((char *)spec, &idx, &vlist);
	}
	va_end(vlist);
	return (idx);
}
