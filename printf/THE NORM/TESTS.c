#include <stdio.h>
#include "libftprintf.h"

int main()
{
	int a = 0;
	ft_printf("%12345\n");
	ft_printf("%c 12345\n", 2);
}

/*	gcc *.h *.c *.a | .\a.exe
*	gcc *.h *.c functions/*.c  & .\a.exe
*/
