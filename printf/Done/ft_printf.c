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

#include "ft_printf.h"

int	_ft_printf(const char *spec, va_list vlist)
{
	t_props props;
	int n;

	int length = 0;

	while (*spec)
	{
		if (*spec != '%')
		{
			ft_putchar(*spec);
			length++;
			spec++;
			continue ;
		}
		else
			spec++;

		props.flags = 0U;
		do {
			switch (*spec) {
				case '0': props.flags |= FLAGS_ZEROPAD; spec++; n = 1U; break;
				case '-': props.flags |= FLAGS_LEFT;    spec++; n = 1U; break;
				case '+': props.flags |= FLAGS_PLUS;    spec++; n = 1U; break;
				case ' ': props.flags |= FLAGS_SPACE;   spec++; n = 1U; break;
				case '#': props.flags |= FLAGS_HASH;    spec++; n = 1U; break;
				default :                                 n = 0U; break;
				}
			} while (n);

		props.width = 0U;
    	if (ft_isdigit(*spec)) {
      		props.width = ft_atoi(spec);
			while(ft_isdigit(*spec))
				spec++;
	    }

		props.precision = 0;
		if (*spec == '.')
		{
			props.flags |= FLAGS_PRECISION;
			spec++;
			if (ft_isdigit(*spec))
				props.precision = ft_atoi(spec);
			while(ft_isdigit(*spec))
				spec++;
		}

		if (*spec == 'd' || *spec == 'i' || *spec == 'u'
											|| *spec == 'x' || *spec == 'X')
		{
			if (*spec == 'x' || *spec == 'X')
				props.base = 16;
			else
			{
				props.base = 10;
				props.flags &= ~FLAGS_HASH;
			}

			if (*spec == 'X') {
				props.flags |= FLAGS_UPPERCASE;
				spec++;
			}

			/* no plus or space flag for u, x, X, o, b */
			if ((*spec != 'i') && (*spec != 'd')) {
				props.flags &= ~(FLAGS_PLUS | FLAGS_SPACE);
			}

			/* ignore '0' flag when precision is given */
			if (props.flags & FLAGS_PRECISION) {
				props.flags &= ~FLAGS_ZEROPAD;
			}

			if ((*spec == 'i') || (*spec == 'd'))
			{
				const int value = va_arg(vlist, int);
				length = ft_itoa(value > 0 ? value : -value, props, value > 0, length);
				spec++;
			}
			else
			{
				const unsigned int value = va_arg(vlist, unsigned int);
				length = ft_itoa(value, props, value > 0, length);
			}
		}

		if (*spec == 'p')
		{
			props.width = sizeof(void*) * 2U;
			props.flags |= FLAGS_ZEROPAD | FLAGS_UPPERCASE;
			props.base = 16;
			const unsigned int value = (unsigned int)va_arg(vlist, void*);
			length = ft_itoa(value, props, value > 0, length);
			spec++;
			continue ;
		}

		if (*spec == 'c')
		{
			int l = 1;

			if (!(props.flags & FLAGS_LEFT)) {
				while (l++ < props.width) {
					ft_putchar(' ');
					length++;
				}
			}

			ft_putchar(va_arg(vlist, int));
			length++;

			if (props.flags & FLAGS_LEFT) {
				while (l++ < props.width) {
					ft_putchar(' ');
					length++;
				}
			}

			spec++;
			continue ;
		}

		else if (*spec == '%')
		{
			ft_putchar('%');
			spec++;
			length++;
			continue ;
		}

		else if (*spec == 's')
		{
			const char* p = va_arg(vlist, char*);

			int l = ft_strlen(p);

			if (props.flags & FLAGS_PRECISION) {
				if (l >= props.precision)
					l = props.precision;
			}

			if (!(props.flags & FLAGS_LEFT)) {
				while (l++ < props.width) {
					ft_putchar(' ');
					length++;
				}
			}

			while ((*p != 0) && (!(props.flags & FLAGS_PRECISION) || props.precision--)) {
				ft_putchar(*(p++));
			}
			spec++;

			if (props.flags & FLAGS_LEFT) {
				while (l++ < props.width) {
					ft_putchar(' ');
					length++;
				}
			}

			continue ;
		}
	}
	return(length);
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
