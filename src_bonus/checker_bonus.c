/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:15:46 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/28 10:23:21 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *stacks, char **res)
{
	if (stacks->val_a != NULL)
		free(stacks->val_a);
	if (stacks->val_b != NULL)
		free(stacks->val_b);
	if (res != NULL)
		free(res);
}

void	free_and_print_error(t_stack *stacks, char **res)
{
	free_all(stacks, res);
	write(2, "Error\n", 6);
	exit(1);
}

void	read_std_and_check(char **res)
{
	char	buffer[5];
	int		len;

	while (1)
	{
		len = read(0, buffer, 4);
		buffer[len] = '\0';
		if (len == 0)
			break;

	}
	(void)res;
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
	read_std_and_check(res);
	free_all(&stacks, res);
	ft_printf("OK\n");
	return (0);
}
