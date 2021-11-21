#ifndef FUNC_H
# define FUNC_H

#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	convert(int n, char *base);
int		ft_printf(const char *spec, ...);

#endif
