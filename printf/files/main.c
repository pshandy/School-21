#include <stdio.h>
#include "libftprintf.h"

int main()
{
	printf("->\n");
	char c[] = "tass";
	printf("->%d\n", (unsigned int)&c);
	//int a = ft_printf("%-22s%s:%c12345%%\n", "TEST", "s", 'a');
	//int b = printf("%-22s%s:%c12345%%\n", "TEST", "s", 'a');
	int a = ft_printf("%X%X_\n", 11, 21);
	int b = printf("%X%X_\n", 11, 21);
	printf("%d:%d\n", a, b);
//	ft_printf("%c 12345\n", 2);
}
