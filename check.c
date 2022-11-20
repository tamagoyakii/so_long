/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:43:14 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/18 18:45:26 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len >= 5)
	{
		if (ft_strncmp(&(map_name[len - 4]), ".ber", 4))
			error_exit("Invalid map extention");
	}
	else
		error_exit("Invalid map extention");
}

void	check_boundary(t_map *map_info)
{
	int	row;
	int	col;

	col = -1;
	while (++col < map_info->col)
	{
		if (map_info->map[0][col] != '1'
			|| map_info->map[map_info->row - 1][col] != '1')
			error_exit("The player might run away!");
	}
	row = -1;
	while (++row < map_info->row)
	{
		if (map_info->map[row][0] != '1'
			|| map_info->map[row][map_info->col - 1] != '1')
			error_exit("The player might run away!");
	}
}

void	check_component(t_map *map_info)
{
	int			row;
	int			col;
	static int	count[3];
	char		c;

	map_info->food = 0;
	map_info->step = 0;
	row = -1;
	while (map_info->map[++row])
	{
		col = -1;
		while (map_info->map[row][++col])
		{
			c = map_info->map[row][col];
			if (c == '0' || c == '1')
				continue ;
			else if (c == 'C' || c == 'E' || c == 'P')
				add_count(count, map_info, row, col);
			else
				error_exit("Invalid component included");
		}
	}
	if (count[0] != 1 || count[1] < 1 || count[2] != 1)
		error_exit("Wrong number of components");
}

void	add_count(int *count, t_map *map_info, int row, int col)
{
	if (map_info->map[row][col] == 'E')
		count[0] += 1;
	if (map_info->map[row][col] == 'C')
	{
		count[1] += 1;
		map_info->food = count[1];
	}
	if (map_info->map[row][col] == 'P')
	{
		count[2] += 1;
		map_info->p_row = row;
		map_info->p_col = col;
	}
}
