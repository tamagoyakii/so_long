/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:43:14 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/17 13:30:48 by jihyukim         ###   ########.fr       */
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
	return ;
}

void	check_boundary(t_map *map)
{
	int	row;
	int	column;

	column = -1;
	while (++column < map->column)
	{
		if (map->map[0][column] != '1'
			|| map->map[map->row - 1][column] != '1')
			error_exit("The player might run away!");
	}
	row = -1;
	while (++row < map->row)
	{
		if (map->map[row][0] != '1'
			|| map->map[row][map->column - 1] != '1')
			error_exit("The player might run away!");
	}
	return ;
}

void	get_object_count(int *count, t_map *map)
{
	(*count)++;
	map->collectible = *count;
}

void	get_player_position(int *count, t_map *map, int x, int y)
{
	(*count)++;
	map->player_x = x;
	map->player_y = y;
}

void	check_component(t_map *map)
{
	int			row;
	int			column;
	static int	count[3];

	row = -1;
	while (map->map[++row])
	{
		column = -1;
		while (map->map[row][++column])
		{
			if (map->map[row][column] == '0' || map->map[row][column] == '1')
				continue ;
			else if (map->map[row][column] == 'C')
				get_object_count(&count[0], map);
			else if (map->map[row][column] == 'E')
				count[1]++;
			else if (map->map[row][column] == 'P')
				get_player_position(&count[2], map, column, row);
			else
				error_exit("Invalid component included");
		}
	}
	if (count[0] < 1 || count[1] != 1 || count[2] != 1)
		error_exit("Invalid component included");
}