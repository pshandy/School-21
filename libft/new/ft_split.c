/*
* char **ft_split(char const *s, char c);
*
* Allocates (with malloc(3)) and returns an array
* of strings obtained by splitting ’s’ using the
* character ’c’ as a delimiter. The array must be
* ended by a NULL pointer.
*
* The array of new strings resulting from the split.
* NULL if the allocation fails.
*/

#include "libft.h"

size_t	getsize(char const *str, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == c || str[i] == '\0')
			len++;
		i++;
	}
	return(len + 1);
}

char **ft_split(char const *s, char c)
{
	char	**str;
	size_t	len;
	size_t	i;
	size_t	j;

	str = malloc(sizeof(char **) * getsize(s, c));
	if (str == NULL)
		return (NULL);
	len = ft_strlen(s) + 1;
	i = 0;
	j = 0;
	while(len--)
	{
		if (s[i] == '\0' || s[i] == c)
		{
			str[j] = ft_strdup(ft_substr(s, 0, i));
			if (str[j] == 0)
			{
				while(j)
				{
					free(str[j]);
					j--;
				}
			}
			j++;
			s = s + 1 + i;
			i = 0;
		} else
			i++;
	}
	str[j] = 0;
	return(str);
}
