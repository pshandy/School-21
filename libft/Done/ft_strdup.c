/*
* char	*ft_strdup(const char *s)
*
* Returns a pointer to a new string which is
* a duplicate of the string s.
*
* Return: On success, the strdup() function returns a pointer
* to the duplicated string. It returns NULL if
* insufficient memory was available
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*result;

	size = strlen(s) + 1;
	result = malloc(size);
	if (result == 0)
		return (0);
	return ((char *)memcpy(result, s, size));
}
