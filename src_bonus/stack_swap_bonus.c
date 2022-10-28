/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:47:55 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/28 11:52:49 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_a(t_stack *stacks)
{
	int		tmp;

	if (stacks->len_a <= 1)
		return ;
	tmp = stacks->val_a[stacks->len_a - 1];
	stacks->val_a[stacks->len_a - 1] = stacks->val_a[stacks->len_a - 2];
	stacks->val_a[stacks->len_a - 2] = tmp;
}

void	swap_b(t_stack *stacks)
{
	int		tmp;

	if (stacks->len_b <= 1)
		return ;
	tmp = stacks->val_b[stacks->len_b - 1];
	stacks->val_b[stacks->len_b - 1] = stacks->val_b[stacks->len_b - 2];
	stacks->val_b[stacks->len_b - 2] = tmp;
}

void	swap_both(t_stack *stacks)
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
}
