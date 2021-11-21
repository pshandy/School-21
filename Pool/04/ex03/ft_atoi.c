/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:51:04 by pshandy           #+#    #+#             */
/*   Updated: 2021/08/24 09:51:06 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*getsign(char *str, int *sign)
{
	while (*str <= ' ' || *str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign = *sign + 1;
		str++;
	}
	return (str);
}

int	getresult(char *str)
{
	int	base;
	int	result;

	base = 1;
	result = 0;
	while (*str <= '9' && *str >= '0')
	{
		result = result + (*str - '0') * base;
		base = base * 10;
		str--;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	*sign_;
	int	result;

	sign = 0;
	sign_ = &sign;
	str = getsign(str, sign_);
	while (*str <= '9' && *str >= '0')
	{
		str++;
	}
	str--;
	result = getresult(str);
	if (sign % 2 != 0)
		result = -result;
	return (result);
}
