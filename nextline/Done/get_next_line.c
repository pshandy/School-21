/*
 * char *get_next_line(int fd);
 * Returns a line read from a file descriptor
 * Return value: Read line: correct behavior
 * NULL: nothing else to read or an error occurred
 */

#include "get_next_line.h"


 /**********************************************************************/

#include <unistd.h>

void ftwrite(char *str) {

	char *strc = str;

	while (*strc)
	{
		write(1, strc, 1);
		strc++;
	}
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ftwrite2(char *str, int n) {

	char *strc = str;

	while (n--)
	{
		write(1, strc, 1);
		strc++;
	}
}

  /**********************************************************************/

int	check(char **list, char **line)
{
	size_t i;

	i = 0;
	while (*(*list + i) != '\n')
	{
		if (*(*list + i) == '\0')
			return (0);
		i++;
	}
	*(*list + i) = '\0';
	*line = ft_strdup(*list);
	*list = ft_strdup((*list + i + 1));
	return (1);
}

int read_file(int fd, char **list, char **buffer, char **line) {

	int		bread;

	bread = read(fd, *buffer, BUFFER_SIZE);
	while (bread > 0)
	{
		*(*buffer + bread) = '\0';
		if (*list)
			*list = ft_strjoin(*list, *buffer);
		else
			*list = ft_strdup(*buffer);
		if (check(list, line))
			break ;
		bread = read(fd, *buffer, BUFFER_SIZE);
	}
	return (bread);
}

char *get_next_line(int fd)
{
	static char	*list[MAX_FD];
	char	*buffer;
	char	*line;
	int		bread;

	if (fd < 0 || fd > MAX_FD || read(fd, list[fd], 0) < 0)
		return (NULL);

	if (list[fd])
		if (check(&list[fd], &line))
			printf("%s\n", line);

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	ft_memset(buffer, 0, (BUFFER_SIZE + 1));

	bread = read_file(fd, &list[fd], &buffer, &line);
	free(buffer);
	if (list[fd][0] != '\0')
		printf("FFF");
	if (bread != 0 || list[fd][0] != '\0')
	{
		if (!bread && *line)
			printf("->%s\n", line);
		return (NULL);
	}

	line = list[fd];
	list[fd] = NULL;
	printf("->%s\n", line);
}

int main()
{
	int	fd;

	fd = open("Poem.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
}
