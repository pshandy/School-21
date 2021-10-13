int		ft_atoi(const char *nptr)
{
	char	sign;
	int		result;

	while(ft_isspace(*nptr))
		nptr++;
	sign = '+';
	if (*nptr == '-')
	{
		sign = '-';
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	result = 0;
	while(ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	if (sign == '-')
		return(-result);
	return(result);
}
