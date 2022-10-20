/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:28:02 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/20 11:52:28 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	long	res;
	long	neg;

	i = 0;
	res = 0;
	neg = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		if ((res > 2147483647 && neg == 1) || (res > 2147483648 && neg == -1))
			return (-1 + (neg < 0));
		i++;
	}
	return (res * neg);
}

long	ft_atol(const char *nptr)
{
	int		i;
	long	res;
	long	neg;

	i = 0;
	res = 0;
	neg = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * neg);
}

int	is_int(char *str)
{
	int		i;
	int		len;
	long	test;

	len = ft_strlen(str);
	if (len == 0 || len > 11)
		return (0);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i != len)
		return (0);
	test = ft_atol(str);
	if (test > 2147483647 || test < -2147483648)
		return (0);
	return (1);
}
