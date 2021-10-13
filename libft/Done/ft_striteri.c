/*
* s - The string on which to iterate.
* f - The function to apply to each character.
*
* Applies the function f to each character of the
* string passed as argument, and passing its index
* as first argument. Each character is passed by
* address to f to be modified if necessary
*
* Return None.
*/

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int i;

	if (s && f)
	{
		i = 0;
		while(s[i] != '\0')
		{
			f(i, s + i);
			i++;
		}
	}
	return ;
}
