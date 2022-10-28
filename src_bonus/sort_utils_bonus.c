/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:52:51 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/28 10:59:12 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_sort(t_stack *stacks)
{
	int	i;

	if (stacks->len_b > 0)
		return (0);
	i = 0;
	while (i < stacks->len_a)
	{
		if (stacks->val_a[i] != stacks->len_a - i - 1)
			return (0);
		i++;
	}
	return (1);
}

int	is_part_sort(t_stack *stacks, char s)
{
	int	i;
	int	len;
	int	*tab;

	len = stacks->len_a;
	tab = stacks->val_a;
	if (s == 'b')
	{
		len = stacks->len_b;
		tab = stacks->val_b;
	}
	if (len > 0)
		return (0);
	i = 0;
	while (i < len)
	{
		if (tab[i] != len - i - 1)
			return (0);
		i++;
	}
	return (1);
}

int	is_in_order(t_stack *stacks, char s)
{
	int	i;

	if (s == 'a')
	{
		i = 1;
		while (i < stacks->len_a)
		{
			if (stacks->val_a[i - 1] < stacks->val_a[i])
				return (0);
			i++;
		}
		return (1);
	}
	i = 1;
	while (i < stacks->len_b)
	{
		if (stacks->val_b[i - 1] < stacks->val_b[i])
			return (0);
		i++;
	}
	return (1);
}

int	get_lower_in_stack(t_stack *stacks, char s)
{
	int	i;
	int	min;
	int	len;
	int	*tab;

	len = stacks->len_a;
	tab = stacks->val_a;
	if (s == 'b')
	{
		len = stacks->len_b;
		tab = stacks->val_b;
	}
	if (len == 0)
		return (-1);
	min = tab[0];
	i = 1;
	while (i < len)
	{
		if (min > tab[i])
			min = tab[i];
		i++;
	}
	return (min);
}

int	all_stack_over(t_stack *stacks, char s, int value)
{
	int	i;
	int	len;
	int	*tab;

	len = stacks->len_a;
	tab = stacks->val_a;
	if (s == 'b')
	{
		len = stacks->len_b;
		tab = stacks->val_b;
	}
	i = 0;
	while (i < len)
	{
		if (tab[i] < value)
			return (0);
		i++;
	}
	return (1);
}
