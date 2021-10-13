/*
* c - The integer to output.
* fd - The file descriptor on which to write.
*
* Outputs the integer ’n’ to the given file
* descriptor
*
* Return None.
*/

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		n = n + '0';
		ft_putchar(n);
	}
}
