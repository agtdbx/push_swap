/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:56:52 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/08 11:42:41 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	little_aglo_sort(t_stack *stacks, char ***res)
{
	int	top_a;
	int	top_val_a;
	int	top_b;

	top_a = stacks->len_a - 1;
	top_b = stacks->len_b - 1;
	top_val_a = stacks->val_a[top_a];
	if (stacks->val_a[top_a - 1] -1 == top_val_a)
	{
		if (top_b >= 0 && abs(stacks->val_b[top_b] - top_val_a) == 1)
			push_a(stacks, res);
		reverse_rotate_a(stacks, res);
	}
	else if (top_a > 0 && stacks->val_a[top_a - 1] + 1 == top_val_a)
		swap_a(stacks, res);
	else if (top_b >= 0 && abs(stacks->val_b[top_b] - top_val_a) == 1)
		push_a(stacks, res);
	else if (top_a > 0 && abs(stacks->val_a[top_a - 1] - top_val_a) == 1)
		reverse_rotate_a(stacks, res);
	else if (top_a > 1 && stacks->val_a[top_a - 2] -1 == top_val_a)
		swap_a(stacks, res);
	else if (top_a > 1 && abs(stacks->val_a[0] - top_val_a) == 1)
		reverse_rotate_a(stacks, res);
	else
		push_b(stacks, res);
}

void	little_aglo(t_stack *stacks, char ***res)
{
	int	top_a;
	int	top_b;

	top_a = stacks->len_a - 1;
	top_b = stacks->len_b - 1;
	if (!is_in_order(stacks, 'a'))
		little_aglo_sort(stacks, res);
	else
	{
		if (abs(stacks->val_a[top_a] - stacks->val_b[top_b]) > 1
			&& abs(stacks->val_a[0] - stacks->val_b[top_b]) > 1)
			rotate_a(stacks, res);
		else
		{
			push_a(stacks, res);
			top_a = stacks->len_a - 1;
			if (stacks->val_a[0] + 1 == stacks->val_a[top_a])
				rotate_a(stacks, res);
		}
	}
}

void	my_little_sort(t_stack *stacks, char ***res)
{
	int	nb;

	nb = 0;
	while (!is_sort(stacks) && nb < 50)
	{
		little_aglo(stacks, res);
		nb++;
	}
}
