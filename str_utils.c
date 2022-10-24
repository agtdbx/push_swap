/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:39:33 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/24 11:33:37 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_params(int argc, char **argv)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char));
	res[0] = '\0';
	i = 1;
	while (i < argc)
	{
		res = ft_strjoin_free(res, argv[i]);
		res = ft_strjoin_free(res, " ");
		i++;
	}
	return (res);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (len == 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	while (s[start + i] != '\0' && i < len)
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	is_empty_param(int argc, char **argv)
{
	int		i;
	size_t	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (!(argv[i][j] >= '0' && argv[i][j] <= '9') && argv[i][j] != '\0')
			j++;
		if (ft_strlen(argv[i]) == j || ft_strlen(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
