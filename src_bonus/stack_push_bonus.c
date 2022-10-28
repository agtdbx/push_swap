/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:09:41 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/28 12:14:19 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push_a(t_stack *stacks)
{
	int	tmp;

	if (stacks->len_b == 0)
		return ;
	tmp = stacks->val_b[stacks->len_b - 1];
	stacks->val_a[stacks->len_a] = tmp;
	stacks->len_b--;
	stacks->len_a++;
}

void	push_b(t_stack *stacks)
{
	int	tmp;

	if (stacks->len_a == 0)
		return ;
	tmp = stacks->val_a[stacks->len_a - 1];
	stacks->val_b[stacks->len_b] = tmp;
	stacks->len_a--;
	stacks->len_b++;
}
