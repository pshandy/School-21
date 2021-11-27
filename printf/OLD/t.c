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
