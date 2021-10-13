/*
* s1 - The prefix string.
* s2 - The suffix string.
* len - The maximum length of the substring.
*
* Description Allocates (with malloc(3)) and returns a new
* string, which is the result of the concatenation
* of ’s1’ and ’s2’.
*
* Return value The new string. NULL if the allocation fails.
*/

int ft_strlen(const char *str);

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*strc;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if(str == NULL)
		return(NULL);
	strc = str;
	while(*s1 != '\0')
		*str++ = *s1++;
	while(*s2 != '\0')
		*str++ = *s2++;
	*str = '\0';
	return(strc);
}
