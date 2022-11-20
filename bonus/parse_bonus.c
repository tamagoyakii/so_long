/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:23:36 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/18 21:44:23 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_row(char *map_name)
{
	int		fd;
	int		row;
	int		res;
	char	buf;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error_exit(0);
	row = 0;
	res = read(fd, &buf, 1);
	while (res > 0)
	{
		if (buf == '\n')
			row++;
		res = read(fd, &buf, 1);
	}
	close(fd);
	if (res == -1)
		error_exit(0);
	return (row);
}

void	get_map(t_map *map_info, char *map_name, int fd)
{
	int		idx;

	map_info->row = get_row(map_name);
	map_info->map = (char **)ft_calloc(map_info->row + 1, sizeof(char *));
	if (!(map_info->map))
		error_exit(0);
	if (get_next_line(fd, &(map_info->map[0])) >= 0)
	{
		map_info->col = ft_strlen(map_info->map[0]);
		idx = 1;
		while (idx < map_info->row
			&& get_next_line(fd, &(map_info->map[idx])) >= 0)
		{
			if ((int)ft_strlen(map_info->map[idx]) != map_info->col)
				error_exit("Map must be rectangle");
			idx++;
		}
		if (idx == map_info->row)
			return ;
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
