/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:53:01 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/27 16:29:43 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_print_error(t_stack *stacks, char **res)
{
	if (stacks->val_a != NULL)
		free(stacks->val_a);
	if (stacks->val_b != NULL)
		free(stacks->val_b);
	if (res != NULL)
		free(res);
	write(2, "Error\n", 6);
	exit(1);
}

void	print_result_and_free(t_stack *stacks, char **res)
{
	int	i;

	i = 0;
	while (res[i] != NULL)
	{
		ft_printf("%s\n", res[i]);
		i++;
	}
	if (stacks->val_a != NULL)
		free(stacks->val_a);
	if (stacks->val_b != NULL)
		free(stacks->val_b);
	if (res != NULL)
		free(res);
}

char	**joined_instructions(char **tmp, char **res, int *i)
{
	*i = 0;
	while (res[*i + 1] != NULL)
	{
		if ((ft_strcmp(res[*i], "ra") == 0
				&& ft_strcmp(res[*i + 1], "rb") == 0)
			|| (ft_strcmp(res[*i], "rb") == 0
				&& ft_strcmp(res[*i + 1], "ra") == 0))
		{
			tmp = add_word(tmp, "rr");
			(*i)++;
		}
		else if ((ft_strcmp(res[*i], "rra") == 0
				&& ft_strcmp(res[*i + 1], "rrb") == 0)
			|| (ft_strcmp(res[*i], "rrb") == 0
				&& ft_strcmp(res[*i + 1], "rra") == 0))
		{
			tmp = add_word(tmp, "rrr");
			(*i)++;
		}
		else
			tmp = add_word(tmp, res[*i]);
		(*i)++;
	}
	return (tmp);
}

char	**optimise_res(char **res)
{
	char	**tmp;
	int		i;

	tmp = malloc(sizeof(char *));
	if (tmp == NULL)
		return (res);
	tmp[0] = NULL;
	if (res[0] == NULL || res[1] == NULL)
	{
		free(tmp);
		return (res);
	}
	tmp = joined_instructions(tmp, res, &i);
	tmp = add_word(tmp, res[i]);
	free(res);
	return (tmp);
}

int	main(int argc, char **argv)
{
	t_stack	stacks;
	char	**res;
	int		error;

	if (argc == 1)
		return (1);
	stacks = check_and_parse_params(argc, argv);
	stacks.len_b = 0;
	stacks.val_b = malloc(sizeof(int) * (stacks.len_a));
	res = malloc(sizeof(char *));
	if (stacks.len_a == 0 || stacks.val_b == NULL || res == NULL)
		free_and_print_error(&stacks, res);
	res[0] = NULL;
	error = standardization(&stacks);
	if (error)
		free_and_print_error(&stacks, res);
	if (stacks.len_a <= 5)
		my_little_sort(&stacks, &res);
	else
		sort(&stacks, &res);
	res = optimise_res(res);
	print_result_and_free(&stacks, res);
	return (0);
}
