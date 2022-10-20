/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:05:46 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/07 13:42:04 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);

void	ft_print_char(char c, int *nb_char_print);
void	ft_print_string(char *str, int *nb_char_print);
void	ft_print_int(int nb, int *nb_char_print);
void	ft_print_uint(unsigned int nb, int *nb_char_print);

void	ft_print_lowerhex(unsigned int nb, int *nb_char_print);
void	ft_print_upperhex(unsigned int nb, int *nb_char_print);
void	ft_print_pointer(void *p, int *nb_char_print);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

size_t	ft_strlen(const char *str);

#endif
