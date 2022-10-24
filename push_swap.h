/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:53:37 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/24 12:54:44 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"

typedef struct s_stack
{
	int	*val_a;
	int	*val_b;
	int	len_a;
	int	len_b;
}	t_stack;

// push_swap.c
void	print_stacks(t_stack *stacks);
void	free_and_print_error(t_stack *stacks, char **res);
void	print_result_and_free(t_stack *stacks, char **res);
int		main(int argc, char **argv);

// params.c
void	free_params_vars(char *jparams, char **params);
int		is_valid_params(char **params);
int		is_in_stack(t_stack *stacks, int nb);
void	fill_stack(t_stack *stacks, char **params);
t_stack	check_and_parse_params(int argc, char **argv);

// str_utils.c
char	*join_params(int argc, char **argv);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		is_empty_param(int argc, char **argv);

// str_utils2.c
char	*ft_strdup(const char *s);
char	*ft_strjoin_free(char *s1, char *s2);
char	**add_word(char **tab, char *word);
char	**ft_split(char const *s, char c);

// nbr_utils.c
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
int		is_int(char *str);
int		abs(int value);

// stack_utils.c
void	add_to_stack(t_stack *stacks, int nb);
int		*create_and_init_tmp(t_stack *stacks);
void	standard_number(t_stack *stacks, int **tmp, int *value);
int		standardization(t_stack *stacks);
int		get_pos_in_stack(t_stack *stacks, char stack, int value);

// stack_swap.c
void	swap_a(t_stack *stacks, char ***res);
void	swap_b(t_stack *stacks, char ***res);
void	swap_both(t_stack *stacks, char ***res);

// stack_push.c
void	push_a(t_stack *stacks, char ***res);
void	push_b(t_stack *stacks, char ***res);

//stack_rotate.c
void	rotate_a(t_stack *stacks, char ***res);
void	rotate_b(t_stack *stacks, char ***res);
void	rotate_both(t_stack *stacks, char ***res);

//stack_reverse_rotate.c
void	reverse_rotate_a(t_stack *stacks, char ***res);
void	reverse_rotate_b(t_stack *stacks, char ***res);
void	reverse_rotate_both(t_stack *stacks, char ***res);

//sort_utils.c
int		is_sort(t_stack *stacks);
int		is_in_order(t_stack *stacks, char s);
int		get_lower_in_stack(t_stack *stacks, char s);

//little_sort.c
void	my_little_sort(t_stack *stacks, char ***res);

#endif
