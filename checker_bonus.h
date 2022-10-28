/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:53:37 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/28 13:59:58 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"
# include "get_next_line_bonus.h"

typedef struct s_stack
{
	int	*val_a;
	int	*val_b;
	int	len_a;
	int	len_b;
}	t_stack;

void	free_all(t_stack *stacks, char **res);
void	free_and_print_error(t_stack *stacks, char **res);
int		check_buffer(char ***res, char *buffer);
int		read_std_and_check(char ***res);
int		main(int argc, char **argv);

void	free_params_vars(char *jparams, char **params);
int		is_valid_params(char **params);
int		is_in_stack(t_stack *stacks, int nb);
void	fill_stack(t_stack *stacks, char **params);
t_stack	check_and_parse_params(int argc, char **argv);

char	*join_params(int argc, char **argv);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		is_empty_param(int argc, char **argv);
int		ft_strcmp(char *s1, char *s2);

char	*ft_strdup(const char *s);
char	*ft_strjoin_free(char *s1, char *s2);
char	**add_word(char **tab, char *word);
char	**ft_split(char const *s, char c);

int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
int		is_int(char *str);
int		abs(int value);

void	add_to_stack(t_stack *stacks, int nb);
int		*create_and_init_tmp(t_stack *stacks);
void	standard_number(t_stack *stacks, int **tmp, int *value);
int		standardization(t_stack *stacks);
int		get_pos_in_stack(t_stack *stacks, char stack, int value);

void	swap_a(t_stack *stacks);
void	swap_b(t_stack *stacks);
void	swap_both(t_stack *stacks);

void	push_a(t_stack *stacks);
void	push_b(t_stack *stacks);

void	rotate_a(t_stack *stacks);
void	rotate_b(t_stack *stacks);
void	rotate_both(t_stack *stacks);

void	reverse_rotate_a(t_stack *stacks);
void	reverse_rotate_b(t_stack *stacks);
void	reverse_rotate_both(t_stack *stacks);

int		is_sort(t_stack *stacks);
int		is_part_sort(t_stack *stacks, char s);
int		is_in_order(t_stack *stacks, char s);
int		get_lower_in_stack(t_stack *stacks, char s);
int		all_stack_over(t_stack *stacks, char s, int value);

int		sort(t_stack *stacks, char **res);

#endif
