#include "libft.h"
#include "func.h"

#include <stdio.h>

/*
 • %c print a single character.
 • %s print a string of characters.
 • %p The void * pointer argument is printed in hexadecimal.
 • %d print a decimal (base 10) number.
 • %i print an integer in base 10.
 • %u print an unsigned decimal (base 10) number.
 • %x print a number in hexadecimal (base 16), with lowercase.
 • %X print a number in hexadecimal (base 16), with uppercase.
 • %% print a percent sign.

 •-0.
 •# +
 */

/* FLAGS */

#define FLAGS_ZEROPAD   (1U <<  0U) // '0'
#define FLAGS_LEFT      (1U <<  1U) // '-'
#define FLAGS_PLUS      (1U <<  2U) // '+'
#define FLAGS_SPACE     (1U <<  3U) // ' '
#define FLAGS_HASH      (1U <<  4U) // '#'
#define FLAGS_PRECISION (1U <<  5U) // '.'
#define FLAGS_UPPERCASE (1U <<	6U) // Uppercase

void ntoa(unsigned long value, unsigned int flags, unsigned long base)
{
	char buf[32];
	size_t len = 0U;

	if (!value) {
		flags &= ~FLAGS_HASH;
	}
	if (!(flags & FLAGS_PRECISION) || value)
		do {
			const char digit = (char)(value % base);
			buf[len++] = digit < 10 ? '0' + digit : (flags & FLAGS_UPPERCASE ? 'A' : 'a') + digit - 10;
			value /= base;
			} while (value && (len < 32));

	buf[len] = '\0';

    for (int i = 0; (unsigned int)i < len/2; i++)
    {
        char temp = buf[i];
        buf[i] = buf[len - i - 1];
        buf[len - i - 1] = temp;
    }

	ft_putstr(buf);
}

int _ft_printf(const char *spec, va_list vlist)
{
	unsigned int n;
	unsigned int flags;
	unsigned int precision;
	unsigned int base;

	base = 10U;
	while (*spec)
	{
		if (*spec != '%')
		{
			ft_putchar(*spec);
			spec++;
			continue ;
		}
		else
			spec++;

		/* TO-DO */

		flags = 0U;
		do {
			switch (*spec) {
				case '0': flags |= FLAGS_ZEROPAD; spec++; n = 1U; break;
				case '-': flags |= FLAGS_LEFT;    spec++; n = 1U; break;
				case '+': flags |= FLAGS_PLUS;    spec++; n = 1U; break;
				case ' ': flags |= FLAGS_SPACE;   spec++; n = 1U; break;
				case '#': flags |= FLAGS_HASH;    spec++; n = 1U; break;
				default :                                 n = 0U; break;
				}
			} while (n);

		precision = 0U;
		if (*spec == '.')
		{
			flags |= FLAGS_PRECISION;
			spec++;
			if (ft_isdigit(*spec))
				precision = ft_atoi(spec);
			while(ft_isdigit(*spec))
				spec++;
		}

		if (*spec == 'd' || *spec == 'i' || *spec == 'u' || *spec == 'x' || *spec == 'X')
		{
			if (*spec == 'x' || 'X')
				base = 16U;
			else
			{
				base = 10U;
				flags &= ~FLAGS_HASH;
			}

 			if (*spec == 'X') {
          		flags |= FLAGS_UPPERCASE;
		 		spec++;
       		}

			/* no plus or space flag for u, x, X, o, b */
        	if ((*spec != 'i') && (*spec != 'd')) {
          		flags &= ~(FLAGS_PLUS | FLAGS_SPACE);
        	}

        	/* ignore '0' flag when precision is given */
        	if (flags & FLAGS_PRECISION) {
          		flags &= ~FLAGS_ZEROPAD;
        	}
		}

		/* %c print a single character. */
		if (*spec == 'c')
		{
			ft_putchar(va_arg(vlist, int));
			spec++;
			continue ;
		}

		/* %% print a percent sign. */
		else if (*spec == '%')
		{
			ft_putchar('%');
			spec++;
		}

		/* %p The void * pointer argument is printed in hexadecimal. */
		else if (*spec == 'p')
		{
			ntoa((unsigned long)va_arg(vlist, void*), flags, base);
			spec++;
			continue ;
		}

		/* %s print a string of characters. */
		else if (*spec == 's')
		{
			const char* p = va_arg(vlist, char*);
			while ((*p != 0) && (!(flags & FLAGS_PRECISION) || precision--)) {
				ft_putchar(*(p++));
			}
			spec++;
			continue ;
		}
	}
	return (0); //TO-DO
}

int ft_printf(const char *spec, ...)
{
	int		ret;

	va_list vlist;
	va_start(vlist, spec);
	ret = _ft_printf(spec, vlist);
	va_end(vlist);
	return (ret);
}
