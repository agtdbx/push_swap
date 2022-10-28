/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:57:33 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/07 13:45:13 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char c, int *nb_char_print)
{
	ft_putchar_fd(c, 1);
	*nb_char_print += 1;
}

void	ft_print_string(char *str, int *nb_char_print)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		*nb_char_print += 6;
		return ;
	}
	ft_putstr_fd(str, 1);
	*nb_char_print += ft_strlen(str);
}

void	ft_print_int(int nb, int *nb_char_print)
{
	long	tmp;
	int		cpt;

	tmp = nb;
	cpt = 0;
	if (tmp < 0)
	{
		tmp *= -1;
		cpt++;
	}
	while (tmp >= 10)
	{
		tmp /= 10;
		cpt++;
	}
	cpt++;
	ft_putnbr_fd(nb, 1);
	*nb_char_print += cpt;
}

static void	print_uint(unsigned int nb)
{
	if (nb >= 10)
		print_uint(nb / 10);
	ft_putchar_fd(nb % 10 + '0', 1);
}

void	ft_print_uint(unsigned int nb, int *nb_char_print)
{
	unsigned int	tmp;
	int				cpt;

	cpt = 0;
	tmp = nb;
	while (tmp >= 10)
	{
		tmp /= 10;
		cpt++;
	}
	cpt++;
	print_uint(nb);
	*nb_char_print += cpt;
}
