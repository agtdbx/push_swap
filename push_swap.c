/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:53:01 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/20 12:24:22 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_value(int value)
{
	if (value < 100 && value >= 0)
		ft_printf("  ");
	else if (value >= 0)
		ft_printf(" ");
	else if (value > -100)
		ft_printf(" ");
	ft_printf("%i", value);
}

void	print_stacks(t_stack *stacks)
{
	int	i;

	ft_printf("\n\n");
	i = stacks->len_a - 1;
	if (i < stacks->len_b - 1)
		i = stacks->len_b - 1;
	while (i >= 0)
	{
		if (i < stacks->len_a)
		{
			print_stack_value(stacks->val_a[i]);
			if (stacks->val_a[i] < 10 && stacks->val_a[i] > -10)
				ft_printf(" ");
			ft_printf("    ");
		}
		else
			ft_printf("        ");
		if (i < stacks->len_b)
			print_stack_value(stacks->val_b[i]);
		ft_printf("\n");
		i--;
	}
	ft_printf("-----   -----\n  a       b\n");
}

void	free_and_print_error(t_stack *stacks, char **res)
{

	if (stacks->val_a != NULL)
		free(stacks->val_a);
	if (stacks->val_b != NULL)
		free(stacks->val_b);
	if (res != NULL)
		free(res);
	ft_printf("Error\n");
	exit(1);
}

void	print_result_and_free(t_stack *stacks, char **res)
{
	int	i;

	ft_printf("==========\n  RESULT  \n==========\n");
	i = 0;
	while (res[i] != NULL)
	{
		ft_printf("%s\n", res[i]);
		i++;
	}
	ft_printf("==========\n");
	if (stacks->val_a != NULL)
		free(stacks->val_a);
	if (stacks->val_b != NULL)
		free(stacks->val_b);
	if (res != NULL)
		free(res);
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

	print_stacks(&stacks);

	print_result_and_free(&stacks, res);
	return (0);
}
