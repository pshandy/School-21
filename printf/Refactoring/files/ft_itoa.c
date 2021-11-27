#include "libftprintf.h"

size_t	format(t_props props, char *buf, int len, int sign);
size_t	reverse_print(t_props props, char *buf, int len, int idx);

size_t	ft_itoa(unsigned int value, t_props props, int sign, int idx)
{
	size_t	len;
	int		digit;
	char	buff[32];

	len = 0;
	if (value == 0)
	{
		buff[len++] = '0';
		buff[len] = '\0';
		return (format(props, buff, idx, 1));
	}
	while (value != 0)
	{
		digit = value % props.base;
		if (digit < 10)
			buff[len++] = '0' + digit;
		else if (props.flags & FLAGS_UPPERCASE)
			buff[len++] = 'A' + digit - 10;
		else
			buff[len++] = 'a' + digit - 10;
		value /= props.base;
	}
	buff[len] = '\0';
	return (format(props, buff, idx, sign));
}

size_t	format(t_props props, char *buf, int idx, int sign)
{
	int	len;

	len = ft_strlen(buf);
	if (!(props.flags & FLAGS_LEFT))
	{
		if (props.width && (props.flags & FLAGS_ZEROPAD)
			&& (!sign || (props.flags & (FLAGS_PLUS | FLAGS_SPACE))))
			props.width--;
		while ((len < props.precision) && (len < PRINTF_NTOA_BUFFER_SIZE))
			buf[len++] = '0';
		while ((props.flags & FLAGS_ZEROPAD) && (len < props.width)
			&& (len < PRINTF_NTOA_BUFFER_SIZE))
			buf[len++] = '0';
	}
	if (props.flags & FLAGS_HASH)
	{
		if (!(props.flags & FLAGS_PRECISION) && len
			&& ((len == props.precision) || (len == props.width)))
		{
			len--;
			if (len && (props.base == 16U))
				len--;
			if ((props.base == 16U) && !(props.flags & FLAGS_UPPERCASE)
				&& (len < PRINTF_NTOA_BUFFER_SIZE))
				buf[len++] = 'x';
			else if ((props.base == 16U) && (props.flags & FLAGS_UPPERCASE)
				&& (len < PRINTF_NTOA_BUFFER_SIZE))
				buf[len++] = 'X';
			else if ((props.base == 2U) && (len < PRINTF_NTOA_BUFFER_SIZE))
				buf[len++] = 'b';
			if (len < PRINTF_NTOA_BUFFER_SIZE)
				buf[len++] = '0';
		}
	}
	if (len < PRINTF_NTOA_BUFFER_SIZE)
	{
		if (sign == 0)
			buf[len++] = '-';
		else if (props.flags & FLAGS_PLUS)
			buf[len++] = '+';
		else if (props.flags & FLAGS_SPACE)
			buf[len++] = ' ';
	}
	return (reverse_print(props, buf, len, idx));
}

size_t	reverse_print(t_props props, char *buf, int len, int idx)
{
	int	start_idx;
	int	i;

	i = len;
	start_idx = idx;
	if (!(props.flags & FLAGS_LEFT) && !(props.flags & FLAGS_ZEROPAD))
		while (i++ < props.width)
			ft_putchar(' ', idx++);
	while (len)
		ft_putchar(buf[--len], idx++);
	if (props.flags & FLAGS_LEFT)
		while (idx - start_idx < props.width)
			ft_putchar(' ', idx++);
	return (idx);
}
