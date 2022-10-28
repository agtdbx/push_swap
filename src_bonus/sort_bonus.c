/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:58:30 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/28 12:10:46 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	parse_arg(t_stack *stacks, char **res, int i)
{
	if (ft_strcmp(res[i], "sa") == 0)
		swap_a(stacks);
	else if (ft_strcmp(res[i], "sb") == 0)
		swap_b(stacks);
	else if (ft_strcmp(res[i], "ss") == 0)
		swap_both(stacks);
	else if (ft_strcmp(res[i], "pa") == 0)
		push_a(stacks);
	else if (ft_strcmp(res[i], "pb") == 0)
		push_b(stacks);
	else if (ft_strcmp(res[i], "ra") == 0)
		rotate_a(stacks);
	else if (ft_strcmp(res[i], "rb") == 0)
		rotate_b(stacks);
	else if (ft_strcmp(res[i], "rr") == 0)
		rotate_both(stacks);
	else if (ft_strcmp(res[i], "rra") == 0)
		reverse_rotate_a(stacks);
	else if (ft_strcmp(res[i], "rrb") == 0)
		reverse_rotate_b(stacks);
	else if (ft_strcmp(res[i], "rrr") == 0)
		reverse_rotate_both(stacks);
}

int	sort(t_stack *stacks, char **res)
{
	int	i;

	i = 0;
	while (res[i] != NULL)
	{
		parse_arg(stacks, res, i);
		i++;
	}
	return (is_sort(stacks));
}
