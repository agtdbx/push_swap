/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:47:55 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/20 11:59:31 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stacks, char ***res)
{
	int		tmp;

	if (stacks->len_a <= 1)
		return ;
	tmp = stacks->val_a[stacks->len_a - 1];
	stacks->val_a[stacks->len_a - 1] = stacks->val_a[stacks->len_a - 2];
	stacks->val_a[stacks->len_a - 2] = tmp;
	*res = add_word(*res, "sa");
}

void	swap_b(t_stack *stacks, char ***res)
{
	int		tmp;

	if (stacks->len_b <= 1)
		return ;
	tmp = stacks->val_b[stacks->len_b - 1];
	stacks->val_b[stacks->len_b - 1] = stacks->val_b[stacks->len_b - 2];
	stacks->val_b[stacks->len_b - 2] = tmp;
	*res = add_word(*res, "sb");
}

void	swap_both(t_stack *stacks, char ***res)
{
	int		tmp;

	if (stacks->len_a <= 1 || stacks->len_b <= 1)
		return ;
	tmp = stacks->val_a[stacks->len_a - 1];
	stacks->val_a[stacks->len_a - 1] = stacks->val_a[stacks->len_a - 2];
	stacks->val_a[stacks->len_a - 2] = tmp;
	tmp = stacks->val_b[stacks->len_b - 1];
	stacks->val_b[stacks->len_b - 1] = stacks->val_b[stacks->len_b - 2];
	stacks->val_b[stacks->len_b - 2] = tmp;
	*res = add_word(*res, "ss");
}
