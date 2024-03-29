/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:10:24 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/19 16:33:28 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find(char *newline, char c)
{
	int			i;

	i = 0;
	while (newline[i])
	{
		if (newline[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	in_line(char **newline, char **line, int i)
{
	char		*ret;

	(*newline)[i] = 0;
	*line = ft_strdup(*newline);
	if (!*line)
		return (-1);
	ret = ft_strdup(*newline + i + 1);
	if (!ret)
		return (-1);
	free(*newline);
	*newline = ret;
	return (1);
}

int	backup(char **newline, char **line, int r)
{
	int			new_idx;

	if (r < 0)
		return (-1);
	if (*newline == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	new_idx = ft_find(*newline, '\n');
	if (new_idx >= 0)
		return (in_line(newline, line, new_idx));
	*line = ft_strdup(*newline);
	if (!*line)
		return (-1);
	free(*newline);
	*newline = 0;
	return (0);
}

int	buf_temp(char *buf, char **newline, int rd_size, int *new_idx)
{
	char		*temp;

	buf[rd_size] = 0;
	temp = ft_strjoin(*newline, buf);
	if (!temp)
		return (-1);
	free(*newline);
	*newline = temp;
	*new_idx = ft_find(*newline, '\n');
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*newline[OPEN_MAX];
	char		*buf;
	int			rd_size;
	int			new_idx;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	rd_size = read(fd, buf, BUFFER_SIZE);
	while (rd_size > 0)
	{
		if (buf_temp(buf, &newline[fd], rd_size, &new_idx) < 0)
			return (-1);
		if (new_idx >= 0)
		{
			free(buf);
			return (in_line(&newline[fd], line, new_idx));
		}
		rd_size = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (backup(&newline[fd], line, rd_size));
}
