int	ft_isupper(int c);
int	ft_islower(int c);

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
