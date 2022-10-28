/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:16:55 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/28 11:52:24 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	reverse_rotate_a(t_stack *stacks)
{
	int	tmp;
	int	i;

	if (stacks->len_a <= 1)
		return ;
	tmp = stacks->val_a[0];
	i = 1;
	while (i < stacks->len_a)
	{
		stacks->val_a[i - 1] = stacks->val_a[i];
		i++;
	}
	stacks->val_a[stacks->len_a - 1] = tmp;
}

void	reverse_rotate_b(t_stack *stacks)
{
	int	tmp;
	int	i;

	if (stacks->len_b <= 1)
		return ;
	tmp = stacks->val_b[0];
	i = 1;
	while (i < stacks->len_b)
	{
		stacks->val_b[i - 1] = stacks->val_b[i];
		i++;
	}
	stacks->val_b[stacks->len_b - 1] = tmp;
}

void	reverse_rotate_both(t_stack *stacks)
{
	int	tmp;
	int	i;

	if (stacks->len_a <= 1 || stacks->len_b <= 1)
		return ;
	tmp = stacks->val_a[0];
	i = 1;
	while (i < stacks->len_a)
	{
		stacks->val_a[i - 1] = stacks->val_a[i];
		i++;
	}
	stacks->val_a[stacks->len_a - 1] = tmp;
	tmp = stacks->val_b[0];
	i = 1;
	while (i < stacks->len_b)
	{
		stacks->val_b[i - 1] = stacks->val_b[i];
		i++;
	}
	stacks->val_b[stacks->len_b - 1] = tmp;
}
