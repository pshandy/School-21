/*
 * char *get_next_line(int fd);
 *
 * Returns a line read from a file descriptor
 *
 * Return value Read line: correct behavior
 * NULL: nothing else to read or an error occurred
 */

 #include <stdio.h>
 #include <fcntl.h>
 #include <stdlib.h>
 #include <unistd.h>

 #define BUFF_SIZE 64
 # define MAX_FD 1024

 static char			*ft_strdup(const char *s1)
 {
 	char		*s2;
 	size_t		i;

 	i = 0;
 	while (s1[i])
 		i += 1;
 	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
 		return (NULL);
 	i = -1;
 	while (s1[++i])
 		s2[i] = s1[i];
 	s2[i] = '\0';
 	return (s2);
 }

 static char			*ft_strjoin(char const *s1, char const *s2)
 {
 	char		*s3;
 	char		*tmp_s3;
 	size_t		i;
 	size_t		j;

 	j = 0;
 	i = 0;
 	while (s1[i])
 		i += 1;
 	while (s2[j])
 		j += 1;
 	if (!s1 || !s2 || !(s3 = (char *)malloc(sizeof(char) * (i + j + 1))))
 		return (NULL);
 	tmp_s3 = s3;
 	while (*s1 != '\0')
 		*tmp_s3++ = *s1++;
 	while (*s2 != '\0')
 		*tmp_s3++ = *s2++;
 	*tmp_s3 = '\0';
 	return (s3);
 }

 /**********************************************************************/

void ftwrite(char *str) {

	char *strc = str;

	while (*strc)
	{
		write(1, strc, 1);
		strc++;
	}
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

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
		*ptr++ = c;
	return (s);
}


int check(char *list, char *line) {
	int	i;

	i = 0;
	while (list[i] != '\n')
	{
		if (list[i] == '\0')
			return (0);
		i++;
	}
	list[i] = '\0';
	printf("--->%s<---\n", list);
	line = ft_strdup(list);
	printf("--->%s<---\n", line);
	list = ft_strdup(&list[i] + 1);
	printf("--->%s<---\n", list);
	//printf("--->%s<---\n", line);
	//printf("--->%s<---\n", list);
	return (1);
}

void read_file(int fd, char *buffer, char *list, char *line) {
	int	bytesread;

	bytesread = read(fd, buffer, BUFF_SIZE);
	while (bytesread > 0)
	{
		buffer[bytesread] = '\0';
		if (list)
			list = ft_strjoin(list, buffer);
		else
			list = ft_strdup(buffer);
		if (check(list, line))
			break ;
		bytesread = read(fd, buffer, BUFF_SIZE);
	}
	//printf("--->%s<---\n", list);
}

char *get_next_line(int fd)
{
	static char	*list[MAX_FD];
	char		*buffer;
	char		*line;

	if (fd < 0 || fd > MAX_FD || read(fd, list[fd], 0) < 0)
		return (NULL);

	buffer = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	ft_memset(buffer, 0, BUFF_SIZE);

	//if (list[fd])
		//if (check(list[fd], line))
			//return (line);

	read_file(fd, buffer, list[fd], line);
	return (line);
}

int main()
{
	int fd = open("Poem.txt", O_RDONLY);
	get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
}
