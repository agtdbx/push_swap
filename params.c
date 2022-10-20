/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:02:46 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/20 11:52:17 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_params_vars(char *jparams, char **params)
{
	int		i;

	free(jparams);
	i = 0;
	while (params != NULL && params[i] != NULL)
	{
		free(params[i]);
		i++;
	}
	free(params);
}

int	is_valid_params(char **params)
{
	int	i;

	i = 0;
	while (params != NULL && params[i] != NULL)
	{
		if (is_int(params[i]) == 0)
			return (0);
		i++;
	}
	if (i > 0)
		return (1);
	return (0);
}

int	is_in_stack(t_stack *stacks, int nb)
{
	int	i;

	i = 0;
	while (i < stacks->len_a)
	{
		if (stacks->val_a[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

void	fill_stack(t_stack *stacks, char **params)
{
	int	i;
	int	tmp;

	i = 0;
	while (params != NULL && params[i] != NULL)
	{
		tmp = ft_atoi(params[i]);
		if (is_in_stack(stacks, tmp))
		{
			free(stacks->val_a);
			stacks->len_a = 0;
			return ;
		}
		add_to_stack(stacks, tmp);
		i++;
	}
}

t_stack	check_and_parse_params(int argc, char **argv)
{
	t_stack	stacks;
	char	*jparams;
	char	**params;

	jparams = join_params(argc, argv);
	params = ft_split(jparams, ' ');
	stacks.len_a = 0;
	if (is_valid_params(params) == 0)
	{
		free_params_vars(jparams, params);
		return (stacks);
	}
	stacks.val_a = malloc(sizeof(int));
	if (stacks.val_a == NULL)
		return (stacks);
	fill_stack(&stacks, params);
	free_params_vars(jparams, params);
	return (stacks);
}
