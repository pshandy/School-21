#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define FLAGS_ZEROPAD   1 // 1 <<  0 '0'
# define FLAGS_LEFT      2 // 1 <<  1 '-'
# define FLAGS_PLUS      4 // 1 <<  2 '+'
# define FLAGS_SPACE     8 // 1 <<  3 ' '
# define FLAGS_HASH      16 // 1 << 4 '#'
# define FLAGS_PRECISION 32 // 1 << 5 '.'
# define FLAGS_UPPERCASE 64 // 1 << 6 Uppercase

typedef struct s_properties
{
	int	base;
	int	width;
	int	flags;
	int	precision;
}				t_props;

int		ft_printf(const char *spec, ...);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
void	ft_putchar(char c, int index);
size_t	ft_strlen(const char *str);
#endif
