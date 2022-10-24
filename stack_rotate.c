/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:27:43 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/21 15:37:04 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stacks, char ***res)
{
	int	tmp;
	int	i;

	if (stacks->len_a <= 1)
		return ;
	tmp = stacks->val_a[stacks->len_a - 1];
	i = stacks->len_a - 2;
	while (i >= 0)
	{
		stacks->val_a[i + 1] = stacks->val_a[i];
		i--;
	}
	stacks->val_a[0] = tmp;
	*res = add_word(*res, "ra");
}

void	rotate_b(t_stack *stacks, char ***res)
{
	int	tmp;
	int	i;

	if (stacks->len_b <= 1)
		return ;
	tmp = stacks->val_b[stacks->len_b - 1];
	i = stacks->len_b - 2;
	while (i >= 0)
	{
		stacks->val_b[i + 1] = stacks->val_b[i];
		i--;
	}
	stacks->val_b[0] = tmp;
	*res = add_word(*res, "rb");
}

void	rotate_both(t_stack *stacks, char ***res)
{
	int	tmp;
	int	i;

	if (stacks->len_a <= 1 || stacks->len_b <= 1)
		return ;
	tmp = stacks->val_a[stacks->len_a - 1];
	i = stacks->len_a - 2;
	while (i >= 0)
	{
		stacks->val_a[i + 1] = stacks->val_a[i];
		i--;
	}
	stacks->val_a[0] = tmp;
	tmp = stacks->val_b[stacks->len_b - 1];
	i = stacks->len_b - 2;
	while (i >= 0)
	{
		stacks->val_b[i + 1] = stacks->val_b[i];
		i--;
	}
	stacks->val_b[0] = tmp;
	*res = add_word(*res, "rr");
}
