#include <stdio.h>
#include "libft.h"

char *ft_strchr(const char *str, int c)
{
	while(1)
	{
		if (*str == c)
			return((char *)str);
		if (*str == '\0')
			return(0);
		str++;
	}
}

int main() {

    printf("1:%s\n", ft_strchr("Text", 't'));

	/*
	**	ft_isalpha()
	*/

	printf("---isalpha test---\n");

	char isalpha_test[] = {'a', 'b', '1', 'G', '/', 'S'};
	for (int i = 0; i < 6; i++)
		printf("%c: %d\n", isalpha_test[i], ft_isalpha(isalpha_test[i]));

	/*
	**	ft_isdigit()
	*/

	printf("---isdigit test---\n");

	char isdigit_test[] = {'1', '2', '3', '1', '-', 'm'};
	for (int i = 0; i < 6; i++)
		printf("%c: %d\n", isdigit_test[i], ft_isdigit(isdigit_test[i]));

	/*
	**	ft_isalnum()
	*/

	printf("---isalnum test---\n");

	char isalnum_test[] = {'1', '2', '3', '1', '-', 'm'};
	for (int i = 0; i < 6; i++)
		printf("%c: %d\n", isalnum_test[i], ft_isalnum(isalnum_test[i]));

	/*
	**	ft_isascii()
	*/

	// char isascii_test[] = {'1', '2', '3', '1', '-', 'm'};
	// for (int i = 0; i < 6; i++)
	// 	printf("%c: %d\n", isascii_test[i], ft_isascii(isascii_test[i]));
}
