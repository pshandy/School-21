#include <string.h>
#include <stdio.h>
 #include <fcntl.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		while(*s != '\0')
			{
				write(fd, &*s, 1);
				s++;
			}
}

int main() {
	int i;
	i = open("text.txt", O_WRONLY);
	if (i == -1)
		printf("BEACH\n");
	ft_putstr_fd("ABCsdasdasd", i);
}
