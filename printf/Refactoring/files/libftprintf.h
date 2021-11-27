#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
#include <stdio.h>

# define FLAGS_ZEROPAD   1 // 1U <<  0U '0'
# define FLAGS_LEFT      2 // 1U <<  1U '-'
# define FLAGS_PLUS      4 // 1U <<  2U '+'
# define FLAGS_SPACE     8 // 1U <<  3U ' '
# define FLAGS_HASH      16 // 1U << 4U '#'
# define FLAGS_PRECISION 32 // 1U << 5U '.'
# define FLAGS_UPPERCASE 64 // 1U << 6U Uppercase
# define PRINTF_NTOA_BUFFER_SIZE 32

typedef struct s_properties
{
	int	base;
	int	width;
	int	flags;
	int	precision;
}				t_props;

int		ft_printf(const char *spec, ...);

//functions
void	ft_putchar(char c, int idx);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
size_t	ft_itoa(unsigned int value, t_props props, int sign, int idx);

#endif
