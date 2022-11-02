/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:45:44 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/02 15:47:01 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_end_a(t_stack *stacks, char ***res)
{
	int	top_b;
	int	total_len;
	int	len_bot_a;

	top_b = stacks->val_b[stacks->len_b - 1];
	total_len = stacks->len_a + stacks->len_b;
	len_bot_a = get_pos_in_stack(stacks, 'a', total_len - 1);
	if (stacks->len_a > 0 && (len_bot_a == 0 || stacks->val_a[0] < top_b))
	{
		push_a(stacks, res);
		rotate_a(stacks, res);
		return (1);
	}
	return (0);
}

void	put_pivot_top(t_stack *stacks, char ***res, int pivot, int pos)
{
	int	action;

	while (pos != stacks->len_b - 1)
	{
		action = push_end_a(stacks, res);
		if (pos == stacks->len_b - 1)
			break ;
		if (pos >= stacks->len_b / 2 && action == 0)
			rotate_b(stacks, res);
		else if (action == 0)
			reverse_rotate_b(stacks, res);
		pos = get_pos_in_stack(stacks, 'b', pivot);
	}
}

void	sort_push_a(t_stack *stacks, char ***res)
{
	int	pivot;
	int	pos;

	pivot = stacks->len_a + stacks->len_b - 1;
	while (stacks->len_b > 0)
	{
		pos = get_pos_in_stack(stacks, 'b', pivot);
		if (pos == -1)
		{
			reverse_rotate_a(stacks, res);
			pivot--;
			continue ;
		}
		put_pivot_top(stacks, res, pivot, pos);
		push_a(stacks, res);
		pivot--;
	}
	while (is_sort(stacks) == 0)
		reverse_rotate_a(stacks, res);
}

void	butterfly_push_b_pivot(t_stack *stacks, char ***res,
		int pivot1, int pivot2)
{
	while (all_stack_over(stacks, 'a', pivot2) == 0)
	{
		if (stacks->val_a[stacks->len_a - 1] > pivot2)
			rotate_a(stacks, res);
		else if (stacks->val_a[stacks->len_a - 1] > pivot1)
		{
			push_b(stacks, res);
			rotate_b(stacks, res);
		}
		else
			push_b(stacks, res);
	}
}

void	sort(t_stack *stacks, char ***res)
{
	int	pivot1;
	int	pivot2;
	int	i;
	int	len;
	int	max;

	if (is_sort(stacks))
		return ;
	i = 0;
	max = (stacks->len_a + stacks->len_b) / 50;
	len = 0;
	while (i < max)
	{
		len = stacks->len_a / max + len;
		pivot1 = len / 3 + stacks->len_b;
		pivot2 = (len / 3) * 2 + stacks->len_b;
		butterfly_push_b_pivot(stacks, res, pivot1, pivot2);
		i++;
	}
	while (stacks->len_a > 0)
		push_b(stacks, res);
	sort_push_a(stacks, res);
}
