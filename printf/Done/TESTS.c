#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char c[] = "tass";
	//int a = ft_printf("%-22s%s:%c12345%%\n", "TEST", "s", 'a');
	//int b = printf("%-22s%s:%c12345%%\n", "TEST", "s", 'a');
	int a = ft_printf("%p\n", &c);
	int b = printf("%p\n", &c);
	printf("%d:%d\n", a, b);
//	ft_printf("%c 12345\n", 2);
}

/*	gcc *.h *.c *.a | .\a.exe
	gcc *.h *.c functions/*.c  & .\a.exe
    gcc -Wall -Wextra -Werror files/*.h files/*.c & .\a.exe
*/
