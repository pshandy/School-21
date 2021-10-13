/*
* c - The character to output.
* fd - The file descriptor on which to write.
*
* Outputs the character
*
* Return None.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
