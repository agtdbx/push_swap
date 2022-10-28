/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:15:46 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/28 13:46:39 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	check_buffer(char ***res, char *buffer)
{
	if (ft_strcmp(buffer, "sa\n") == 0)
		*res = add_word(*res, "sa");
	else if (ft_strcmp(buffer, "sb\n") == 0)
		*res = add_word(*res, "sb");
	else if (ft_strcmp(buffer, "ss\n") == 0)
		*res = add_word(*res, "ss");
	else if (ft_strcmp(buffer, "pa\n") == 0)
		*res = add_word(*res, "pa");
	else if (ft_strcmp(buffer, "pb\n") == 0)
		*res = add_word(*res, "pb");
	else if (ft_strcmp(buffer, "ra\n") == 0)
		*res = add_word(*res, "ra");
	else if (ft_strcmp(buffer, "rb\n") == 0)
		*res = add_word(*res, "rb");
	else if (ft_strcmp(buffer, "rr\n") == 0)
		*res = add_word(*res, "rr");
	else if (ft_strcmp(buffer, "rra\n") == 0)
		*res = add_word(*res, "rra");
	else if (ft_strcmp(buffer, "rrb\n") == 0)
		*res = add_word(*res, "rrb");
	else if (ft_strcmp(buffer, "rrr\n") == 0)
		*res = add_word(*res, "rrr");
	else
		return (0);
	return (1);
}

int	read_std_and_check(char ***res)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (check_buffer(res, line) == 0)
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
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
	if (read_std_and_check(&res) == 0)
		free_and_print_error(&stacks, res);
	if (sort(&stacks, res))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_all(&stacks, res);
	return (0);
}
