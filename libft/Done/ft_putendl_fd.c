/*
* void ft_putendl_fd(char *s, int fd)
* s - The string to output.
* fd - The file descriptor on which to write.
*
* Outputs the string ’s’ to the given file descriptor, followed by a newline.
*
* Return: None.
*/

#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
	if (s != NULL)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd)
	}
}
