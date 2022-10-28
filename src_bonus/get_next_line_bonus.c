/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:10:43 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/28 13:51:01 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_and_check(char *buffer, char *read_buffer, int *read_len, int fd)
{
	int	len;

	*read_len = read(fd, read_buffer, BUFFER_SIZE);
	if (*read_len > -1)
		read_buffer[*read_len] = '\0';
	len = ft_strlen2(buffer);
	if (*read_len <= 0 && len == 0)
	{
		free(read_buffer);
		free(buffer);
		return (NULL);
	}
	return (read_buffer);
}

char	*read_line(char *buffer, int fd, int *end_file)
{
	char	*read_buffer;
	int		read_len;
	int		end_line;

	end_line = get_end_line(buffer);
	if (end_line == -1)
	{
		read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (read_buffer == NULL)
			return (NULL);
		read_buffer[0] = '\0';
		read_buffer = read_and_check(buffer, read_buffer, &read_len, fd);
		if (read_buffer == NULL)
		{
			*end_file = 1;
			return (NULL);
		}
		buffer = ft_strjoin(buffer, read_buffer);
		end_line = get_end_line(buffer);
		if (end_line == -1 && read_len == BUFFER_SIZE)
			buffer = complete_buffer(buffer, read_buffer, end_file, fd);
		free(read_buffer);
	}
	return (buffer);
}

char	*complete_buffer(char *buffer, char *read_buffer, int *end_file, int fd)
{
	int	read_len;
	int	end_line;

	read_len = BUFFER_SIZE;
	end_line = get_end_line(buffer);
	while (end_line == -1 && read_len == BUFFER_SIZE)
	{
		read_len = read(fd, read_buffer, BUFFER_SIZE);
		read_buffer[read_len] = '\0';
		buffer = ft_strjoin(buffer, read_buffer);
		end_line = get_end_line(buffer);
	}
	if (read_len != BUFFER_SIZE)
		*end_file = 1;
	return (buffer);
}

void	buffer_shift(char *buffer, int shift)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen2(buffer);
	while (i + shift < len)
	{
		buffer[i] = buffer[i + shift];
		i++;
	}
	buffer[i] = '\0';
}

char	*get_next_line(int fd)
{
	static t_buf	buffer;
	char			*res;
	int				end_line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer.buffer == NULL && buffer.end_file == 0)
	{
		buffer.buffer = malloc(sizeof(char));
		if (buffer.buffer == NULL)
			return (NULL);
		buffer.buffer[0] = '\0';
	}
	if (buffer.end_file == 0)
		buffer.buffer = read_line(buffer.buffer, fd,
				&(buffer.end_file));
	end_line = get_end_line(buffer.buffer) + 1;
	if (end_line == -1)
		return (NULL);
	if (end_line == 0)
		end_line = ft_strlen2(buffer.buffer);
	res = ft_substr2(buffer.buffer, 0, end_line);
	buffer_shift(buffer.buffer, end_line);
	free_buffer(&(buffer.buffer), buffer.end_file);
	return (res);
}
