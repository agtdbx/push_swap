/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:46:12 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/28 10:58:54 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	add_to_stack(t_stack *stacks, int nb)
{
	int	*res;
	int	i;

	res = malloc(sizeof(int) * (stacks->len_a + 1));
	if (res == NULL)
		return ;
	i = 0;
	while (i < stacks->len_a)
	{
		res[i] = stacks->val_a[i];
		i++;
	}
	res[i] = nb;
	free(stacks->val_a);
	stacks->val_a = res;
	stacks->len_a++;
}

int	*create_and_init_tmp(t_stack *stacks)
{
	int	*tmp;
	int	i;

	tmp = malloc(sizeof(int) * stacks->len_a);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (i < stacks->len_a)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}

void	standard_number(t_stack *stacks, int **tmp, int *value)
{
	int	i;
	int	max;
	int	place;

	i = 1;
	max = stacks->val_a[0];
	place = 0;
	while (i < stacks->len_a)
	{
		if (stacks->val_a[i] > max)
		{
			max = stacks->val_a[i];
			place = i;
		}
		i++;
	}
	(*tmp)[place] = *value;
	stacks->val_a[place] = -2147483648;
	(*value)--;
}

int	standardization(t_stack *stacks)
{
	int	*tmp;
	int	value;

	tmp = create_and_init_tmp(stacks);
	if (tmp == NULL)
		return (1);
	value = stacks->len_a -1;
	while (value > 0)
		standard_number(stacks, &tmp, &value);
	free(stacks->val_a);
	stacks->val_a = tmp;
	return (0);
}

int	get_pos_in_stack(t_stack *stacks, char stack, int value)
{
	int	i;
	int	size;
	int	*tab;

	size = stacks->len_a;
	tab = stacks->val_a;
	if (stack == 'b')
	{
		size = stacks->len_b;
		tab = stacks->val_b;
	}
	i = 0;
	while (i < size)
	{
		if (tab[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
