#include "get_next_line.h"

char	*ft_strdup(const char *s1)
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

char	*ft_strjoin(char const *s1, char const *s2)
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

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
		*ptr++ = c;
	return (s);
}
