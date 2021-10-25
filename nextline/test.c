#include <stdio.h>

int main()
{
	int i = 0;
	char buffer[10];
	while (i < 10)
	{
		buffer[i++] = 100;
		printf("%d->%d\n", buffer[0], i);
	}
}
