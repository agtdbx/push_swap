/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:10:43 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/08 11:54:45 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	i = ft_strlen2(s1);
	j = ft_strlen2(s2);
	res = malloc(sizeof(char) * (i + j + 1));
	if (res == NULL)
		return (res);
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(s1);
	return (res);
}

char	*get_next_line(int fd)
{
	char	*res;
	char	buffer[2];
	int		read_len;

	if (fd < 0)
		return (NULL);
	res = malloc(sizeof(char));
	if (res == NULL)
		return (NULL);
	res[0] = '\0';
	buffer[0] = '\0';
	buffer[1] = '\0';
	read_len = read(fd, buffer, 1);
	if (read_len <= 0)
	{
		free(res);
		return (NULL);
	}
	while (read_len > 0 && buffer[0] != '\n')
	{
		res = ft_strjoin(res, buffer);
		read_len = read(fd, buffer, 1);
	}
	res = ft_strjoin(res, buffer);
	return (res);
}
