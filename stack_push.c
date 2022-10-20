/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:09:41 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/20 12:01:04 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stacks, char ***res)
{
	int	tmp;

	if (stacks->len_b == 0)
		return ;
	tmp = stacks->val_b[stacks->len_b - 1];
	stacks->val_a[stacks->len_a] = tmp;
	stacks->len_b--;
	stacks->len_a++;
	*res = add_word(*res, "pa");
}

void	push_b(t_stack *stacks, char ***res)
{
	int	tmp;

	if (stacks->len_a == 0)
		return ;
	tmp = stacks->val_a[stacks->len_a - 1];
	stacks->val_b[stacks->len_b] = tmp;
	stacks->len_a--;
	stacks->len_b++;
	*res = add_word(*res, "pb");
}
