/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:23:36 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/18 16:56:30 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_row(t_map *map_info, char *map_name)
{
	int		fd;
	char	buf;
	int		res;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error_exit(0);
	map_info->row = 0;
	res = read(fd, &buf, 1);
	while (res > 0)
	{
		if (buf == '\n')
			map_info->row++;
		res = read(fd, &buf, 1);
	}
	close(fd);
	if (res == -1)
		error_exit(0);
	return (map_info->row);
}

void	get_map(t_map *map_info, char *map_name, int fd)
{
	int		idx;
	size_t	row_len;

	map_info->row = get_row(map_info, map_name);
	map_info->map = (char **)ft_calloc(map_info->row + 1, sizeof(char *));
	if (!(map_info->map))
		error_exit(0);
	if (get_next_line(fd, &(map_info->map[0])) >= 0)
	{
		row_len = ft_strlen(map_info->map[0]);
		idx = 1;
		while (idx < map_info->row
			&& get_next_line(fd, &(map_info->map[idx])) >= 0)
		{
			if (ft_strlen(map_info->map[idx]) != row_len)
				error_exit("Map must be rectangle");
			idx++;
		}
		if (idx == map_info->row)
		{
			map_info->col = row_len;
			return ;
		}
	}
	error_exit("Map parsing failed");
}

void	map_parse(t_info *info, char *map_name)
{
	int	fd;

	check_ber(map_name);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error_exit(0);
	get_map(&info->map, map_name, fd);
	close(fd);
	check_boundary(&info->map);
	check_component(&info->map);
}
