/*
 * int	ft_isspace(int c)
 *
 * Returns non-zero if c is a white-space character;
 * otherwise, returns 0.
 */

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}
