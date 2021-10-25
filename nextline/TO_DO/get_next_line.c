/*
 * char *get_next_line(int fd);
 * Returns a line read from a file descriptor
 * Return value: Read line: correct behavior
 * NULL: nothing else to read or an error occurred
 */

#include "get_next_line.h"
#include "get_next_line_utils.c"

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
			return (line);

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	ft_memset(buffer, 0, (BUFFER_SIZE + 1));

	bread = read_file(fd, &list[fd], &buffer, &line);
	free(buffer);

	if (bread != 0 || list[fd] == NULL || list[fd][0] == '\0')
	{
		if (!bread && line)
			line = NULL;
		return (line);
	}
	line = list[fd];
	list[fd] = NULL;
	return (line);
}

#include <stdio.h>

int main()
{
	int	fd;

	fd = open("Poem.txt", O_RDONLY);
	for (int i = 0; i < 20; i++)
		printf("->%s\n", get_next_line(fd));
}
